
int B_AnalogPin = A0;
int AnalogReading;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Starts the serial communication
AnalogReading=analogRead (B_AnalogPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("Volt:  ");
  Serial.println(AnalogReading);
  
  delay(10);
  


}
