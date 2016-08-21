#include <avr/io.h>
#include <util/delay.h>

char c;

void SPI_MasterInit(void)
{
 /* Set MOSI and SCK output, all others input */
 DDRB = (1<<DDB3)|(1<<DDB5)|(1<<DDB2);
 /* Enable SPI, Master, set clock rate fck/16 */
 SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

char SPI_MasterTransmit(char cData)
{
 /* Start transmission */
 SPDR = cData;
 /* Wait for transmission complete */
 while(!(SPSR & (1<<SPIF)));
 /* Return Data Register */
 return SPDR;
}

void setup(){
  /* Set SS(Slave Select) to High to disable communication */
  PORTB |= (1 << DDB2);
  SPI_MasterInit();
  Serial.begin(115200);
}

void loop(){
  while(Serial.available()){
    c = Serial.read();
    /* Set SS to low to enable communication */
    PORTB &= ~(1 << DDB2);
    /* Print data from register */
    Serial.print(SPI_MasterTransmit(c));
    /* Set SS to low to disable again */
    PORTB |= (1 << DDB2);
  }
}
