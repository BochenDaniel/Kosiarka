//Kod do kosiarki z wykozystaniem Bibliotek.
//Proba takiego kodu w ramach cwiczen.
//Musze jeszcze poprawcowac nad Classami i  ich wykozystaniem.
//11,03,2019





#include "DriveMotor.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 4, 5, 6, 0, 1, 2, 3, 7, POSITIVE); 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  


DriveM driveM(true);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
}
int currentstate=0;
int isruning=0;
int timespent=0;
int lasttimechange=0;
int DriveStop;
int delaytime=1000;
int a=1;


void loop() {

  long rndNo = driveM.GetRandomNumber();
  unsigned long curtime=millis();
  String DM_Msg=driveM.DM_Msg();
  Serial.print(rndNo);
  lcd.setCursor(0,0);
  lcd.print(DM_Msg);
  lcd.setCursor(0,1);
  lcd.print(curtime/1000);
  lcd.setCursor(12,1);
  lcd.print("sec");
  //delay(2000);

  if(isruning){

    if(curtime >(lasttimechange + delaytime)){
      if(currentstate==0){
        isruning=1;
        driveM.DriveStop(a)
      
    }
  }else{  //isrunning loop
    
  }
//if(Bumper)

}
