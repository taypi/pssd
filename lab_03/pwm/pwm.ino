void setup() {
  DDRD |= (1 << DDD6);
  // PD6 is now an output
  TCCR0A |= (1 << COM0A1);
  // set none-inverting mode
  TCCR0A |= (1 << WGM01) | (1 << WGM00);
  // set fast PWM Mode
  TCCR0B |= (1 << CS10) | (1 << CS11);
  // set prescaler to 8 and starts PWM


}
float cont=0;
void loop() {
    OCR0A = (255*(sin(cont)+1))/2;
    cont+=0.015708;
    // set PWM for 50% duty cycle
    delay(10);
}