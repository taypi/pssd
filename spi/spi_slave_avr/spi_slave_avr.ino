/*
  SPI Slave
  created 18 Aug 2016
  by Hanoch Griner and Taynara Pinheiro

  Refs.:
   * http://www.atmel.com/ptr/br/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_datasheet.pdf
   * http://mlb-d2-p.mlstatic.com/atmega328p-pu-arduino-uno-com-bootloader-oscilador-ebook-22798-MLB20236502126_012015-F.webp?square=false
*/

#include <avr/io.h>
#include <util/delay.h>

/* Incrise the dumb variable to send to master */
int count = 0;

void setup() {
  SPI_SlaveInit();
  Serial.begin(115200);
}

void loop() {
  Serial.print(SPI_SlaveReceive());
}

void SPI_SlaveInit(void)
{
  /* Set MISO output, all others input */
  DDRB |= _BV(4);
  /* Enable SPI */
  SPCR |= (1<<SPE);
}
  
char SPI_SlaveReceive(void)
{
  /* Stores dumb data to send */
  SPDR = 'a' + (count++)%23;
  /* Wait for reception complete */
  while(!(SPSR & (1<<SPIF)));
  /* Return Data Register */
  return SPDR;
}
