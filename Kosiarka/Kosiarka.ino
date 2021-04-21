/*


*/
//#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 4, 5, 6, 0, 1, 2, 3, 7, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);




//defines pins numbers for wheel motor regulation
int ENAPin = 9; //motor A enable
int ENBPin = 10; //motor B enable
int IN1Pin = 4; //motor A
int IN2Pin = 5; //motor A
int IN3Pin = 6; //motor B
int IN4Pin = 7; //motor B

//defines pins for motorblade regulation
int ENCPin = 11; // motor C enable
int IN5Pin = 12; // motor C
int IN6Pin = 13; // motor C

//defines variables for wheel motor regulation
int AForwd = 0;
int ABack = 0;
int BForwd = 0;
int BBack = 0;
int Obstacle = 0;
int MotorSpeedA = 25;
int MotorSpeedB = 25;
int kSpeed = 3;
int BackTime = 1000;
unsigned long Time;
int SwitchPin = 3;  //pin 3 with GND-com on LimitSwitch
int SwitchVal = 0;
int SwitchState = 0;

//-------------------flagi------------
int Drive = 0;
int reverse = 0;
int StopM = 0;
int StopB=0;  
int StartB=0;


 
//bumper
int BumperPin = 2;
int Bumper;




void setup() {
  //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(BumperPin, INPUT); // Sets the Bumper Pin as input
  pinMode(SwitchPin, INPUT ); // Sets switch pin as input - button to start/stop motors
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16, 2);
  lcd.backlight();
  
    lcd.setCursor(1, 0);
    lcd.print("Kosiarka v1.0");
    lcd.setCursor(0,1);
    lcd.print("Ready");

  

}


void loop() {


       
    Bumper=digitalRead(BumperPin);
    SwitchVal=digitalRead(SwitchPin);
//  Time = millis();

//  //-------------------------------------analog--------------------------------
//  
//  //av_analog=0;
//  AnalogReading2=AnalogReading1;
//  
////  for (int i = 0; i< 4 ; i++) {
////    _Arry_Analog[i] = analogRead (B_AnalogPin);
////    AnalogReading = AnalogReading +_Arry_Analog[i];
////
////  }
////  //AnalogReading=analogRead (B_AnalogPin);
////  av_analog=AnalogReading / 4;
////  
//
//AnalogReading1=analogRead (B_AnalogPin);
//  
//  //Serial.print("Average: ");
//  //Serial.println(av_analog);
//  lcd.setCursor(6, 0);
//  //lcd.print(AnalogReading);
//  lcd.print(AnalogReading1);
//  
//
//
//
//  if (AnalogReading1 ==AnalogReading2 && AnalogReading1 <10) {
//    SwitchVal = 0;
//
//  } else {
//    SwitchVal = 1;
//  }



  ////lcd.begin(0,1);
  ////lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("hello world");
  ////lcd.begin(0,2);
  ////lcd.setCursor(12,1);
  ////lcd.print("100%");




//----------------------------Programowanie guzika start stop--------------------------
// Trzeba napisac logike zmiany stanu przykazdym nacisnieciu guzika, new_state, last_state. 
// Albo przypisaywac zamiennie wartosc 0 i 1, if high & = 0 wykonaj 1. 



  
  if (SwitchVal == HIGH) { 
    if (SwitchState == 0) {
      //StopM =0;
      StartB=1;
      Drive = 1;
      SwitchState=1;
      lcd.setCursor(15, 1);
      lcd.print("Y");
      delay(250);

    } else {
      StopM =1;
      StopB=1;
      //Drive = 1;
      SwitchState=0;
      lcd.setCursor(15, 1);
      lcd.print("X");
      delay(250);
    }
  }



//-------------------------------------BumprerValue----------------------------------
//    lcd.setCursor(3, 1);
//    lcd.print(Bumper);

  if (Bumper == HIGH&& SwitchState==1) {

    lcd.setCursor(8, 1);
    lcd.print("Bump=1");
    StopM = 1;
    reverse = 1;
    delay(1);
  }
  else {

    lcd.setCursor(8, 1);
    lcd.print("Bump=0");
    delay(1);
  }

//----------------------------------zatrzymanie napedu --------------------------------------

  if (StopM == 1) { 
    lcd.setCursor(0, 1);
    lcd.print("StoP   ");
//    analogWrite(ENBPin, 255);
//    analogWrite(ENBPin, 255);
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, LOW);

    StopM = 0;
    delay(500);
  }

 // ---------------------------------------wycofanie-----------------------------------
  if (reverse == 1) {
    lcd.setCursor(0, 1);
    lcd.print("Reverse");
   
    // Set Motor A Back
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    // Set Motor B Back
    digitalWrite(IN3Pin, HIGH);
    digitalWrite(IN4Pin, LOW);
    analogWrite(ENAPin, 255);//MotorSpeedA*kSpeed); // Send PWM signal to motor A
    analogWrite(ENBPin, 255);//MotorSpeedB*kSpeed); // Send PWM signal to motor B

    delay(1500);

//--------------------------------------- Obrot----------------------------------

    delay(BackTime / kSpeed);
    
    // Set Motor A Back
    digitalWrite(IN1Pin, HIGH);
    digitalWrite(IN2Pin, LOW);
    // Set Motor B Front
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
    analogWrite(ENAPin, 255);
    analogWrite(ENBPin, 255);

    delay(4500);
    reverse = 0;
    Drive = 1;
  }

// ---------------------------------- Start motorblad-a--------------------

if (StartB==1){
//    lcd.setCursor(3, 1);
//    lcd.print("B");
    // Blade motor start
    // Set Motor C 
    digitalWrite(IN5Pin, LOW);
    digitalWrite(IN6Pin, HIGH);

    analogWrite(ENCPin, 255);
    StartB=0;
}
// ----------------------------------Stop motorblad-a--------------------

if (StopB==1){
//    lcd.setCursor(3, 1);
//    lcd.print("B");
    // Blade motor start
    // Set Motor C 
    digitalWrite(IN5Pin, LOW);
    digitalWrite(IN6Pin, LOW);

    analogWrite(ENCPin, 255);
    StopB=0;
}
//----------------------------------------Jazda do przodu -----------------------------
  if (Drive == 1) {
    lcd.setCursor(0, 1);
    lcd.print("Drive  ");
    // Drive Motor Forward
    // Set Motor A forward
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    // Set Motor B forward
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH);
    analogWrite(ENAPin, 255);//MotorSpeedA*kSpeed); // Send PWM signal to motor A
    analogWrite(ENBPin, 255);//MotorSpeedB*kSpeed); // Send PWM signal to motor B
   
    Drive=0;
  }
}
