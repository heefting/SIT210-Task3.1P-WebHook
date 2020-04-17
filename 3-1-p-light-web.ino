
// Channel stuff

// ID: 

// URL: https://api.thingspeak.com/update

// Write Key: 

// Read Key: 


// Webhooks and sensor data

int led1 = A5;
int led2 = D7;

int photoresistor = A0;
int analogValue;

int second_count = 0;

void setup() {
    
    // Leds
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
    // Photoresistor
    pinMode(photoresistor, INPUT);

}




void loop() {
    
    // Delay 1 seconds
    delay(1000);
    
    // Run second_count timer
    second_count += 1;
    
    // Read photoresistor value
    analogValue = analogRead(photoresistor);
    
    // If on the 30th second : Publish to web
    if (second_count % 30 == 0) {
        // Write result to web database
        // Use event light_level with value converted to string
        Particle.publish("light_level", String::format("%d",analogValue), PRIVATE);
        
        // Reset counter
        second_count = 0;
    }
    
    // Toggle light
    if (analogValue > 10) {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
    } else {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
    }
}



