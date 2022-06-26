#include "RobotCarLib.h"
#include <IRremote.h>
const int32_t KEY_UP = 0xE718FF00;
const int32_t KEY_LEFT = 0xF708FF00;
const int32_t KEY_OK = 0xE31CFF00;
const int32_t KEY_RIGHT = 0xA55AFF00;
const int32_t KEY_DOWN = 0xAD52FF00;
const int32_t KEY_1 = 0xBA45FF00;
const int32_t KEY_2 = 0xB946FF00;
const int32_t KEY_3 = 0xB847FF00;
const int32_t KEY_4 = 0xBB44FF00;
const int32_t KEY_5 = 0xBF40FF00;
const int32_t KEY_6 = 0xBC43FF00;
const int32_t KEY_7 = 0xF807FF00;
const int32_t KEY_8 = 0xEA15FF00;
const int32_t KEY_9 = 0xF609FF00;
const int32_t KEY_0 = 0xE619FF00;
const int32_t KEY_ASTERISK = 0xE916FF00;
const int32_t KEY_POUND = 0xF20DFF00;
const int32_t KEY_REPEAT = 0x0;
const uint8_t speed = 110;
bool inductor = false;
const int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

RobotCarLib robot;

const int waitTime = 2000;
//Atmega 328p (Arduino Uno, Nano)
// Frecuencias
// 5, 6    Timer0   62500 Hz
// 9, 10    Timer1   31250 Hz
// 3, 11    Timer2   31250 Hz

// Prescalers
// 5, 6    Timer0   1 8 64 256 1024
// 9, 10    Timer1   1 8 64 256 1024
// 3, 11    Timer2   1 8 32 64 128 256 1024

// Valores por defecto
// 5, 6    Timer0 64   977Hz
// 9, 10    Timer1 64   490Hz
// 3, 11    Timer2 64   490Hz

// Consecuencias
// 5, 6    Timer0   delay() y millis()
// 9, 10    Timer1   Librería servo
// 3, 11    Timer2   

void setPWMPrescaler(uint8_t pin, uint16_t prescale) {
  
  byte mode;
  
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(prescale) {
      case    1: mode = 0b001; break;
      case    8: mode = 0b010; break;
      case   64: mode = 0b011; break; 
      case  256: mode = 0b100; break;
      case 1024: mode = 0b101; break;
      default: return;
    }
    
  } else if(pin == 3 || pin == 11) {
    switch(prescale) {
      case    1: mode = 0b001; break;
      case    8: mode = 0b010; break;
      case   32: mode = 0b011; break; 
      case   64: mode = 0b100; break; 
      case  128: mode = 0b101; break;
      case  256: mode = 0b110; break;
      case 1024: mode = 0b111; break;
      default: return;
    }
  }
  
  if(pin==5 || pin==6) {
    TCCR0B = TCCR0B & 0b11111000 | mode;
  } else if (pin==9 || pin==10) {
    TCCR1B = TCCR1B & 0b11111000 | mode;
  } else if (pin==3 || pin==11) {
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
void setup()
{
  pinMode(11, OUTPUT);
  //setPWMPrescaler(11, 32);
	robot.Init();
  irrecv.enableIRIn();
  pinMode(2, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
     if (irrecv.decode())
   {
      switch (irrecv.decodedIRData.decodedRawData)
      {
      case KEY_UP:
         robot.MoveBackward();
         break;
      case KEY_LEFT:
         robot.TurnRight();         
         break;
      case KEY_OK:
         robot.Stop();
         break;
      case KEY_RIGHT:
         robot.TurnLeft();
         break;
      case KEY_DOWN:
         robot.MoveForward();
         break;
      case KEY_REPEAT:
         //robot.Stop();
         break;
      case KEY_1:
         //analogWrite(11, 127);
         //Serial.println("KEY1");
         inductor = true;
         break;
      case KEY_2:
         digitalWrite(2, HIGH);
         break;
      case KEY_3:
         digitalWrite(2, LOW);
         break;
      case KEY_4:
         inductor = false;
         break;
      default:
         break;
      }
      irrecv.resume();
   }
   if(inductor){
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        delayMicroseconds(100);
        digitalWrite(11, LOW);
   }
}
