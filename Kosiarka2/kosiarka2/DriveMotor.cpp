#include "DriveMotor.h"

DriveM::DriveM(bool displayMsg){ //class clone, cnstractor
  Serial.print("DriveMotor constructor instaled");

}
/*  
      // Set Motor A forward
    digitalWrite(IN1Pin, LOW);
    digitalWrite(IN2Pin, HIGH);
    // Set Motor B forward
    digitalWrite(IN3Pin, LOW);
    digitalWrite(IN4Pin, HIGH); 
 
analogWrite(ENAPin, 0);//MotorSpeedA*kSpeed); // Send PWM signal to motor A
analogWrite(ENBPin, 230);//MotorSpeedB*kSpeed); // Send PWM signal to motor B

*/
long DriveM::GetRandomNumber()  {

  unsigned long specialNumber = random(5,1000);
  specialNumber *= PI;
  specialNumber -=5;

  _DM_Msg="Random number";
  return specialNumber;
}

void DriveM::DriveStop(int &DS) {

  _DM_Msg="Drive Motors STOP "%DS;

  //return
}

int DriveM::DriveRun() {
  
}
int DriveM::DriveReverseLeft(){
  
}
int DriveM::DriveReverseRight(){
  
}
int DriveM::DriveBack(){
  
}

String DriveM::DM_Msg(){
  
  String dM_Msg=_DM_Msg;

  return dM_Msg;
}


