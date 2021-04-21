/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers for distance measurement
const int trigPin = 12;
const int echoPin = 11;
// defines variables for distance measurement
long duration;
int distance;

//defines pins numbers for wheel motor regulation
int ENAPin=9;   //motor A enable
int ENBPin=10;  //motor B enable
int IN1Pin=4;   //motor A
int IN2Pin=5;   //motor A
int IN3Pin=6;   //motor B
int IN4Pin=7;   //motor B
//defines variables for wheel motor regulation
int AForwd=0;
int ABack=0;
int BForwd=0;
int BBack=0;
int Obstacle=0;
int MotorSpeedA=50;
int MotorSpeedB=50;
int kSpeed=1;
int StopM=0;
int BackTime=1000;

//bumper
int Bumper=2;
int BumperValue;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(Bumper, INPUT); // Sets the Bumper Pin as input
Serial.begin(9600); // Starts the serial communication
}




void loop() {

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
//distance= duration*0.034/2;
distance = (duration/2) / 29.1;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Obstacle: ");
Serial.println(Obstacle);
Serial.print("Motor speed A: ");
Serial.println(MotorSpeedA);
Serial.print("Motor speed B: ");
Serial.println(MotorSpeedB);
Serial.print("Stop: ");
Serial.println(StopM);
Serial.print("kSpeed: ");
Serial.println(kSpeed);
BumperValue = digitalRead(Bumper);
Serial.print ("Wartosc przycisku: ");
Serial.println(BumperValue);


delay(250);


}
