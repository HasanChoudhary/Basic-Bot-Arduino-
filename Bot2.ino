#include<Servo.h>
#include <IRremote.h>
Servo servo1;
Servo servo2;
Servo servo3;
int ledb = 4;
int ledr = 5;
unsigned long previousMillis = 0;
const long interval = 250;
int ledState = LOW;
//Define hex numbers
#define B1 0x9716BE3F
#define B2 0x3D9AE3F7
#define B3 0x6182021B
#define B4 0x8C22657B
#define B5 0x488F3CBB

const int ir = 13;
IRrecv irrecv(ir);
decode_results results;
uint32_t Previous;

void setup() {
  // put your setup code here, to run once:
  
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  pinMode(ledb, OUTPUT); 
  pinMode(ledr, OUTPUT); 
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(ledb, HIGH);
  //delay(250);
  //digitalWrite(ledb, LOW);   
  //delay(250);
  //digitalWrite(ledr, HIGH);
  //delay(250);
  //digitalWrite(ledr, LOW);   
  //delay(250);
  //servo1.write(120);
  //servo2.write(50);
  //servo3.write(40);
  //digitalWrite(ledb, HIGH);
  //delay(250);
  //digitalWrite(ledb, LOW);   
  //delay(250);
  //digitalWrite(ledr, HIGH);
  //delay(250);
  //digitalWrite(ledr, LOW);   
  //delay(250);
  //servo1.write(90);
  //servo2.write(90);
  //servo3.write(90);
  //digitalWrite(ledb, HIGH);
  //delay(250);
  //digitalWrite(ledb, LOW);   
  //delay(250);
  //digitalWrite(ledr, HIGH);
  //delay(250);
  //digitalWrite(ledr,LOW);
  //servo1.write(50);
  //servo2.write(120);
  //servo3.write(120);
  if(irrecv.decode(&results))
  {Serial.println(results.value,HEX);
  irrecv.resume();
  if(results.value == 0xFFFFFFFF)
    {
      results.value=Previous;
    }
    if(results.value == B1)
    {
      servo1.write(180);
      servo2.write(180);
      servo3.write(180);
    }
    if(results.value == B2)
    {
      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
    }
    if(results.value == B3)
    {
      for(int i = 0; i <= 10; i++)
      {
          servo1.write(150);
          delay(250);
          servo2.write(180);
          servo3.write(180);
          servo1.write(100);
          delay(250);
      } 
    }
    if(results.value == B4)
     {
      for(int i = 0; i <= 10; i++)
      {
        servo1.write(80);
        servo2.write(80);
        servo3.write(80);
        delay(250);
        servo1.write(100);
        servo2.write(100);
        servo3.write(100);
        delay(250);
        servo1.write(120);
        servo2.write(120);
        servo3.write(120);
        delay(250);
        servo1.write(140);
        servo2.write(140);
        servo3.write(140);
        delay(500);
      }
     }
     if(results.value == B5)
     {
       for(int i = 0; i <= 10; i++)
      {
          servo1.write(90);
          servo2.write(90);
          servo3.write(90);
          delay(250);
          servo1.write(50);
          servo2.write(90);
          servo3.write(90);
          delay(250);
          servo1.write(110);
          servo2.write(90);
          servo3.write(90); 
          delay(700);
      }
     }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledb, ledState);
    digitalWrite(ledr, !ledState);
  }
 }
}
