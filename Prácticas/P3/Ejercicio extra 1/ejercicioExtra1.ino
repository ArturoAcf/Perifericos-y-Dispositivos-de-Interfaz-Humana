// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Número donde se conecta cada led + salida
}

int primerLED=2; // Variable para controlar el pimer LED

void loop()
{
  // El siguiente condicional tiene como función el
  // controlar la ilumación del primer LED tras
  // cada iteración, ya que al "regresar" al mismo
  // se iluminaba dos veces seguidas.
  if(primerLED%2==0){
  	digitalWrite(13, HIGH);
  	delay(250);
    digitalWrite(13, LOW);
  	delay(250);
  }else{
    digitalWrite(13, LOW);
  	delay(250);
  }

  primerLED++;

  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  digitalWrite(10, HIGH);
  delay(250);
  digitalWrite(10, LOW);
  delay(250);

  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  delay(250);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  delay(250);

  if(primerLED%2==1){
  	digitalWrite(13, HIGH);
  	delay(250);
    digitalWrite(13, LOW);
  	delay(250);
  }else{
    digitalWrite(13, LOW);
  	delay(250);
  }
}
