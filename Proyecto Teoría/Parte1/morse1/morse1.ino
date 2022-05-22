// C++ code
//
String cadena = "";         // Declarar la variable cadena
int numLed = 13;            // Declarar e inicializar el puerto de salida donde está conectado el LED

// Función que le indica al LED cuanto tiempo debe estar encendida para indicar que es un punto (0,5 segundos).
void Punto(){
  digitalWrite(numLed, HIGH);     // Encender LED
  delay(500);                     // Esperar durante 0,5 segundos
  digitalWrite(numLed, LOW);      // Apagar LED
  delay(500);                     // Esperar durante 0,5 segundos
}

// Función que le indica al LED cuanto tiempo debe estar encendida para indicar que es una raya (3 segundos).
void Raya(){
  digitalWrite(numLed, HIGH);     // Encender LED
  delay(3000);                    // Esperar durante 3 segundos
  digitalWrite(numLed, LOW);      // Apagar LED
  delay(500);                     // Esperar durante 0,5 segundos
}

// Función que apaga el LED durante 7 segundos para indicar que se ha cambiado a una palabra nueva.
void Espacio(){
  digitalWrite(numLed, LOW);      // Apagar LED  
  delay(7000);                    // Esperar durante 7 segundos
}

// Función para mostrar la letra pasada como parámetro de entrada
/* La función consta de un condicional switch donde la variable que se va
   a comparar es la letra que se pasa como parámetro de entrada. Respecto
   a los bloques de instrucciones del switch, hemos implementado uno por
   cada letra del abecedario (cada bloque está constituido por dos casos
   posibles que puede cumplir el condicional, la letra en mayúscula y la
   letra en minúscula). Otro por cada número del 0 al 9 y, por último, tres
   bloques de instrucciones dos para los signos de puntuación '.' y ',' y
   el otro para el espacio.
   
   Dentro de cada bloque de instrucciones llama a las funciones raya() o
   punto() de acuerdo al código morse. O a la función Espacio() cuando se
   encuentre con un espacio en la cadena ' '. */
void MostrarLetra(char letra){
  switch (letra) {
    case 'A':
    case 'a':
      Punto();
      Raya();
      break;
    case 'B':
    case 'b':
      Raya();
      Punto();
      Punto();
      Punto();
      break;
    case 'C':
    case 'c':
      Raya();
      Punto();
      Raya();
      Punto();
      break;
    case 'D':
    case 'd':
      Raya();
      Punto();
      Punto();
      break;
    case 'E':
    case 'e':
      Punto();
      break;
    case 'F':
    case 'f':
      Punto();
      Punto();
      Raya();
      Punto();
      break;
    case 'G':
    case 'g':
      Raya();
      Raya();
      Punto();
      break;
    case 'H':
    case 'h':
      Punto();
      Punto();
      Punto();
      Punto();
      break;
    case 'I':
    case 'i':
      Punto();
      Punto();
      break;
    case 'J':
    case 'j':
      Punto();
      Raya();
      Raya();
      Raya();
      break;
    case 'K':
    case 'k':
      Raya();
      Punto();
      Raya();
      break;
    case 'L':
    case 'l':
      Punto();
      Raya();
      Punto();
      Punto();
      break;
    case 'M':
    case 'm':
      Raya();
      Raya();
      break;
    case 'N':
    case 'n':
      Raya();
      Punto();
      break;
    case 'O':
    case 'o':
      Raya();
      Raya();
      Raya();
      break;
    case 'P':
    case 'p':
      Punto();
      Raya();
      Raya();
      Punto();
      break;
    case 'Q':
    case 'q':
      Raya();
      Raya();
      Punto();
      Raya();
      break;
    case 'R':
    case 'r':
      Punto();
      Raya();
      Punto();    
      break;
    case 'S':
    case 's':
      Punto();
      Punto();
      Punto();
      break;
    case 'T':
    case 't':
      Raya();
      break;
    case 'U':
    case 'u':
      Punto();
      Punto();
      Raya();
      break;
    case 'V':
    case 'v':
      Punto();
      Punto();
      Punto();
      Raya();
      break;
    case 'W':
    case 'w':
      Punto();
      Raya();
      Raya();
      break;
    case 'X':
    case 'x':
      Raya();
      Punto();
      Punto();
      Raya();
      break;
    case 'Y':
    case 'y':
      Raya();
      Punto();
      Raya();
      Raya();
      break;
    case 'Z':
    case 'z':
      Raya();
      Raya();
      Punto();
      Punto();
      break;
    case '0':
      Raya();
      Raya();
      Raya();
      Raya();
      Raya();
      break;
    case '1':
      Punto();
      Raya();
      Raya();
      Raya();
      Raya();
      break;
    case '2':
      Punto();
      Punto();
      Raya();
      Raya();
      Raya();
      break;
    case '3':
      Punto();
      Punto();
      Punto();
      Raya();
      Raya();
      break;
    case '4':
      Punto();
      Punto();
      Punto();
      Punto();
      Raya();
      break;
    case '5':
      Punto();
      Punto();
      Punto();
      Punto();
      Punto();
      break;
    case '6':
      Raya();
      Punto();
      Punto();
      Punto();
      Punto();
      break;
    case '7':
      Raya();
      Raya();
      Punto();
      Punto();
      Punto();
      break;
    case '8':
      Raya();
      Raya();
      Raya();
      Punto();
      Punto();
      break;
    case '9':
      Raya();
      Raya();
      Raya();
      Raya();
      Punto();
      break;
    case '.':
      Punto();
      Raya();
      Punto();
      Raya();
      Punto();
      Raya();
      break;
    case ',':
      Raya();
      Raya();
      Punto();
      Punto();
      Raya();
      Raya();
      break;
    case ' ':
      Espacio();
      break;
  }
}

// put your setup code here, to run once:
void setup()
{
  pinMode(numLed, OUTPUT);         // Pin de salida del LED
  cadena = "PDIH, prueba P3";      // Cadena que se quiere traducir de lenguaje natural a morse
  int tam = cadena.length();       // Calcular el tamaño de la cadena

  delay(500);
  int i;
  for (i = 0; i < tam; i += 1){    // Recorrer la cadena letra por letra
    MostrarLetra(cadena[i]);       // Llama a la función MostrarLetra(char letra) pasándole como parámetro
                                   // cada letra de la cadena.
    delay(2000);                   // Se realiza una espera de 2 segundos para marcar el fin de cada letra
  }
}

void loop() { }
