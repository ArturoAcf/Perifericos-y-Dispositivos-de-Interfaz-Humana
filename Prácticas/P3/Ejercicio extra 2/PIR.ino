// C++ code
//

int estadoPIR;

void setup()
{
  pinMode(13,OUTPUT); // LED rojo
  pinMode(2,INPUT); // Sensor PIR
}

void loop()
{
  estadoPIR = digitalRead(2);
  if (estadoPIR == HIGH){
    	digitalWrite(13, HIGH);
  	}else{
    	digitalWrite(13, LOW);
  	}
  delay(10); 
}