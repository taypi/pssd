double tensao;
int bin[8], saida;
byte b, d;

void setup(){
  Serial.begin(9600);
  DDRB |= B00000011;
  DDRD |= B11111100;  
}

void loop(){
  tensao = analogRead(A5);
  Serial.println(tensao);
  saida = tensao*255/1023;
  
  d = saida << 2;
  b = saida >> 6;
  
  PORTB = b;
  PORTD = d;
  
}

