#include <util/delay.h>

byte segmentsB[] = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
byte segmentsD[] = {B11111100, B00011000, B01101100, B00111100, B10011000, B10110100, B11110100, B00011100, B11111100, B10111100};
int cont[4] = {0};

void setup(){
  DDRB |= B00011111;
  DDRD |= B11111100;
}

void loop(){
  if (cont[0]%3 == 0){
    PORTB |= (1 << PORTB4);
    PORTB &= ~(1 << PORTB2);
    PORTB &= ~(1 << PORTB3);
    segmentsB[cont[1]%10] == 1 ? PORTB |= (1 << PORTB0) : PORTB &= ~(1 << PORTB0);
    PORTD = segmentsD[cont[1]%10];
    _delay_ms(5);
  }
  else if (cont[0]%3 == 1){
    PORTB &= ~(1 << PORTB4);
    PORTB |= (1 << PORTB2);
    PORTB &= ~(1 << PORTB3);
    segmentsB[cont[3]%10] == 1 ? PORTB |= (1 << PORTB0) : PORTB &= ~(1 << PORTB0);
    PORTD = segmentsD[cont[3]%10];
    _delay_ms(5);
  }
  else {
    PORTB &= ~(1 << PORTB4);
    PORTB &= ~(1 << PORTB2);
    PORTB |= (1 << PORTB3);
    segmentsB[cont[2]%10] == 1 ? PORTB |= (1 << PORTB0) : PORTB &= ~(1 << PORTB0);
    PORTD = segmentsD[cont[2]%10];
    _delay_ms(5);
  }
  cont[0]++;
  if (cont[0] % 100 == 0)
   cont[3]++;
  if (cont[0] % 1000 == 0)
   cont[2]++;
  if (cont[0] % 10000 == 0)
   cont[1]++; 
}
