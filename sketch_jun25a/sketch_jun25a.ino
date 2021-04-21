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


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
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
distance= duration*0.034/2;
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

delay(250);

if (distance  <= 10){
  Obstacle=1;
}


if (Obstacle==1){

kSpeed=0;

//delay(2000);
Obstacle=0;
StopM=1;
}
    //else {
    //delay(2000);
    //  kSpeed=10;
    //}
  
if (StopM==1) {
    
  // wycofanie 
    // Set Motor A Back
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    // Set Motor B Back
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH); 

    delay(1000);
    kSpeed=3;
    analogWrite(ENAPin, MotorSpeedA*kSpeed); // Send PWM signal to motor A
    analogWrite(ENBPin, MotorSpeedB*kSpeed); // Send PWM signal to motor B

    delay(BackTime);
    // Obrot
    // Set Motor A Back
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    // Set Motor B Front
    digitalWrite(IN4Pin, LOW);
    digitalWrite(IN3Pin, HIGH); 
    
    delay(BackTime);
    StopM=0; 
}

     // Set Motor A forward
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN1Pin, HIGH);
    // Set Motor B forward
    digitalWrite(IN4Pin, LOW);
    digitalWrite(IN3Pin, HIGH); 
 
analogWrite(ENAPin, MotorSpeedA*kSpeed); // Send PWM signal to motor A
analogWrite(ENBPin, MotorSpeedB*kSpeed); // Send PWM signal to motor B
}
