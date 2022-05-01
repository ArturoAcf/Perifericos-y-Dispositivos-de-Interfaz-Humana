// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Número donde se conecta cada led + salida
  pinMode(7, INPUT); // Interruptor deslizante
}

void loop()
{
  if((digitalRead(7)==true)){ // Interruptor ON
    digitalWrite(13, HIGH); // Led rojo encendido
    digitalWrite(11, LOW); // Led amarillo apagado
    digitalWrite(12, LOW); // Led verde apagado
  }else{ // Interrupton OFF
    digitalWrite(13, LOW); // Led rojo apagado
    digitalWrite(11, HIGH); // Led amarillo encendido
    digitalWrite(12, HIGH); // Led verde encendido
  }
}
