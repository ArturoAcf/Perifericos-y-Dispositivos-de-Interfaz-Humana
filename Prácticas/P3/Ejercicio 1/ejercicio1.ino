// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Número donde se conecta cada led + salida
}

void loop()
{
  digitalWrite(11, HIGH); // Led amarillo
  delay(1500); // Pausa de 1.5 segundos
  digitalWrite(11, LOW); // Led amarillo
  delay(3000); // Pausa de 3 segundos
  
  digitalWrite(12, HIGH); // Led verde
  delay(1500); 
  digitalWrite(12, LOW); // Led verde
  delay(3000); 
  
  digitalWrite(13, HIGH); // Led rojo
  delay(1500); 
  digitalWrite(13, LOW); // Led rojo
  delay(3000); 
}