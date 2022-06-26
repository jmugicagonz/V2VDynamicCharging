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

const int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);
void setup()
{
   Serial.begin(9600);
   irrecv.enableIRIn();
}

void loop()
{
   if (irrecv.decode())
   {
      //Serial.println(irrecv.decodedIRData.decodedRawData,HEX);
      switch (irrecv.decodedIRData.decodedRawData)
      {
      case KEY_UP:
         Serial.println("KEY_UP");
         break;
      case KEY_LEFT:
         Serial.println("KEY_LEFT");
         break;
      case KEY_OK:
         Serial.println("KEY_OK");
         break;
      case KEY_RIGHT:
         Serial.println("KEY_RIGHT");
         break;
      case KEY_DOWN:
         Serial.println("KEY_DOWN");
         break;
      case KEY_1:
         Serial.println("KEY_1");
         break;
      case KEY_2:
         Serial.println("KEY_2");
         break;
      case KEY_3:
         Serial.println("KEY_3");
         break;
      case KEY_4:
         Serial.println("KEY_4");
         break;
      case KEY_5:
         Serial.println("KEY_5");
         break;
      case KEY_6:
         Serial.println("KEY_6");
         break;
      case KEY_7:
         Serial.println("KEY_7");
         break;
      case KEY_8:
         Serial.println("KEY_8");
         break;
      case KEY_9:
         Serial.println("KEY_9");
         break;
      case KEY_0:
         Serial.println("KEY_0");
         break;
      case KEY_ASTERISK:
         Serial.println("KEY_ASTERISK");
         break;
      case KEY_POUND:
         Serial.println("KEY_POUND");
         break;
      case KEY_REPEAT:
         Serial.println("KEY_REPEAT");
         break;
      }
      irrecv.resume();
   }
}
