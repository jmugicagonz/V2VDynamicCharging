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
void setup() {
  pinMode(11, OUTPUT);
  setPWMPrescaler(11, 32);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  

}

void loop() {
  analogWrite(11, 127);
  // put your main code here, to run repeatedly:

}
