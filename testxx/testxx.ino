#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 4, 5, 6, 0, 1, 2, 3, 7, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int BumperPin = 2;
int Bumper=0;

void setup() {
  // put your setup code here, to run once:
    //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(BumperPin, INPUT); // Sets the Bumper Pin as input
//  pinMode(SwitchPin, INPUT ); // Sets switch pin as input - button to start/stop motors
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16, 2);
  lcd.backlight();

   Serial.begin(9600);
}

void loop() {
   Bumper=digitalRead(BumperPin);
  // put your main code here, to run repeatedly:
  if (Bumper == HIGH) {

    lcd.setCursor(0, 0);
    lcd.print("bump");
    Serial.println("bump");
 //   StopM = 1;
 //   reverse = 1;
   
//    digitalWrite(IN1Pin, LOW);
//    digitalWrite(IN2Pin, HIGH);
//    digitalWrite(IN3Pin, LOW);
//    digitalWrite(IN4Pin, HIGH);
  }
  else {

    lcd.setCursor(0, 0);
    lcd.print("%bump");
    Serial.println("%bump");
    //delay(50);
  }
   delay(50);
//      lcd.setCursor(3, 1);
//    lcd.print(Bumper);
}
