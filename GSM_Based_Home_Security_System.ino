#include <SoftwareSerial.h>

const String PHONE = "+918830584864";
#define rxPin 11
#define txPin 10

SoftwareSerial sim800(rxPin,txPin);

int pir_sensor = 8;

void setup() {
  pinMode(pir_sensor, INPUT);    
  Serial.begin(115200);       

  sim800.begin(9600);
  Serial.println("SIM800L software serial initialize");

  sim800.println("AT");
  delay(1000);
}

void loop(){
while(sim800.available()){
  Serial.println(sim800.readString());
}
while(Serial.available())  {
  sim800.println(Serial.readString());
}
  int val = digitalRead(pir_sensor);  
  if (val == HIGH) {                  
    //state = HIGH;
    Serial.println("Motion detected!");
    Serial.println("calling....");
    delay(1000);
    sim800.println("ATD"+PHONE+";");
    delay(20000); 
  }
}
