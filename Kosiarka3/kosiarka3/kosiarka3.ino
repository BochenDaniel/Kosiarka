
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 4, 5, 6, 0, 1, 2, 3, 7, POSITIVE); 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  




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
int MotorSpeedA=25;
int MotorSpeedB=25;
int kSpeed=3;
int StopM=0;
int BackTime=1000;
unsigned long Time;
int SwitchPin=2;



//bumper
int Bumper=1;
int BumperValue;

//on/off
int power=1;
int powerstate;

void setup() {
  
// put your setup code here, to run once:

pinMode(Bumper, INPUT); // Sets the Bumper Pin as input
pinMode(SwitchPin, INPUT );
Serial.begin(9600); // Starts the serial communication
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:

}
