#define echoPin 1 // Echo Pin
#define trigPin 0 // Trigger Pin
#define LEDPin 2
#define LEDPin1 3// Onboard LED

int maximumRange = 20; // Maximum range needed

long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); 
 pinMode(LEDPin1, OUTPUT);// Use LED indicator (if required)
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance <= maximumRange ){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */

 digitalWrite(LEDPin, HIGH); 
 digitalWrite(LEDPin1, LOW);
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */

 digitalWrite(LEDPin, LOW); 
 digitalWrite(LEDPin1, HIGH);
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
