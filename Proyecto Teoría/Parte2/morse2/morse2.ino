// C++ code
//
int numPulsadorPunto = 7; // Declarar e inicializar el puerto de entrada
                          // donde está conectado el pulsador para el punto
int numPulsadorRaya = 6;  // Declarar e inicializar el puerto de entrada
                          // donde está conectado el pulsador para la raya
int numPulsador = 5;      // Declarar e inicializar el puerto de entrada
                          // donde está conectado el fin de letra

int const TAM = 10;        // Declarar e inicializar la variable TAM con el
                          // tamaño máximo del vector (6)
int morse_array[TAM];     // Declarar el array donde se van a almacenar la
                          // letra en morse
int tamano;               // Declarar el tamaño que tendrá el array con la
                          // letra

// Función que devuelve la letra correspondiente al código morse que se ha
// introducido como parámetro de entrada
/* Si observamos el código morse podemos clasificar el código según la suma
   de puntos y rayas de cada letra en seis grupos ya que es el número máximo
   de puntos/rayas que hay. Si el tamaño está entre 1 y 4 se va a tratar de
   una letra, si es 5 va a ser un número y por último si es 6 se va a tratar
   de un signo de puntuación.

   Partiendo de esto hemos implementado un condicional if en el cual cada
   bloque de instrucciones se realiza si se cumple que el tamaño pasado
   como parámetro corresponde al valor 1, 2, 3, 4, 5 o 6. Dentro del bloque
   de instrucciones hemos implementado otro condicional if donde comprobamos
   si los valores del array corresponden con el código morse de cada letra
   teniendo en cuenta que el 1 corresponde al punto y el 2 a la raya.
*/
char buscarletra(int tam_array, int *morse){
  char letra = ' ';
  
  if(tam_array == 1){
    if(morse[0] == 1){
      letra = 'E';
    } else if(morse[0] == 2){
      letra = 'T';
    }
  } else if (tam_array == 2){
    if(morse[0] == 1 && morse[1] == 1){
      letra = 'I';
    } else if(morse[0] == 1 && morse[1] == 2){
      letra = 'A';
    } else if(morse[0] == 2 && morse[1] == 1){
      letra = 'N';
    } else if(morse[0] == 2 && morse[1] == 2){
      letra = 'M';
    }
  } else if (tam_array == 3){
    if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1){
      letra = 'S';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 2){
      letra = 'U';
    } else if(morse[0] == 1 && morse[1] == 2 && morse[2] == 1){
      letra = 'R';
    } else if(morse[0] == 1 && morse[1] == 2 && morse[2] == 2){
      letra = 'W';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 1){
      letra = 'D';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 2){
      letra = 'K';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 1){
      letra = 'G';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 2){
      letra = 'O';
    } 
  } else if (tam_array == 4){
    if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1){
      letra = 'H';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2){
      letra = 'V';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 2 && morse[3] == 1){
      letra = 'F';
    } else if(morse[0] == 1 && morse[1] == 2 && morse[2] == 1 && morse[3] == 1){
      letra = 'L';
    } else if(morse[0] == 1 && morse[1] == 2 && morse[2] == 2 && morse[3] == 1){
      letra = 'P';
    } else if(morse[0] == 1 && morse[1] == 2 && morse[2] == 2 && morse[3] == 2){
      letra = 'J';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1){
      letra = 'B';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2){
      letra = 'X';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 2 && morse[3] == 1){
      letra = 'C';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2){
      letra = 'Y';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 1 && morse[3] == 1){
      letra = 'Z';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 1 && morse[3] == 2){
      letra = 'Q';
    }
  } else if (tam_array == 5){
    if(morse[0] == 1 && morse[1] == 2 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2){
      letra = '1';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2){
      letra = '2';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 2 && morse[4] == 2){
      letra = '3';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2){
      letra = '4';
    } else if(morse[0] == 1 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1){
      letra = '5';
    } else if(morse[0] == 2 && morse[1] == 1 && morse[2] == 1 && morse[3] == 1 && morse[4] == 1){
      letra = '6';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 1  && morse[3] == 1 && morse[4] == 1){
      letra = '7';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 2  && morse[3] == 1 && morse[4] == 1){
      letra = '8';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 2  && morse[3] == 2 && morse[4] == 1){
      letra = '9';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 2 && morse[3] == 2 && morse[4] == 2){
      letra = '0';
    }
  } else if (tam_array == 6){
    if(morse[0] == 1 && morse[1] == 2 && morse[2] == 1 && morse[3] == 2 && morse[4] == 1 && morse[5] == 2){
      letra = '.';
    } else if(morse[0] == 2 && morse[1] == 2 && morse[2] == 1 && morse[3] == 1 && morse[4] == 2 && morse[5] == 2){
      letra = ',';
    }
  }
  
  return letra;
}

void setup() {
 // put your setup code here, to run once:
  pinMode(numPulsador, INPUT);        // Pin de entrada del pulsador de fin
                                      // de letra
  pinMode(numPulsadorPunto, INPUT);   // Pin de salida del pulsador del
                                      // punto
  pinMode(numPulsadorRaya, INPUT);    // Pin de salida del pulsador de la
                                      // raya
  Serial.begin(9600);                 // 
  
  
  tamano = 0;                         // Inicializar el tamaño que tendrá
                                      // el vector con la letra
  for(int i = 0; i < TAM; i++){       // Inicializar el array donde se van
                                      // a almacenar la letra en morse
    morse_array[i] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Comprueba si se pulsa el botón del punto
  if ((digitalRead(numPulsadorPunto) == true)) {
    tamano += 1;                    // Aumenta el tamaño que tendrá el array
                                    // donde se almacena la letra
    morse_array[tamano - 1] = 1;    // Almacena el valor 1 en la última
                                    // posición del array indicando que es
                                    // un punto 
    delay(500);                     // Se realiza una espera de 0,5 segundo.
                                    // Para asegurarnos de que se añade solo
                                    // una vez el valor 1 en el array
    //Serial.print(".");              // Muestra por pantalla un '.' Para
                                    // comprobar que entra en el condicional
                                    // cuando se ha pulsado el botón del
                                    // punto

  }
  // Comprueba si se pulsa el botón de la raya
  if ((digitalRead(numPulsadorRaya) == true)) {
    tamano += 1;                    // Aumenta el tamaño que tendrá el array
                                    // donde se almacena la letra
    morse_array[tamano - 1] = 2;    // Almacena el valor 2 en la última
                                    // posición del array indicando que es
                                    // una raya
    delay(500);                     // Se realiza una espera de 0,5 segundo.
                                    // Para asegurarnos de que se añade solo
                                    // una vez el valor 2 en el array
    //Serial.print("-");              // Muestra por pantalla un '-' Para
                                    // comprobar que entra en el condicional
                                    // cuando se ha pulsado el botón de la
                                    // raya
  }
  
  // Comprueba si se pulsa el botón de fin de letra
  if ((digitalRead(numPulsador) == true)) {
    // Declarar la variable letra e asignarle el valor del resultado de la
    // función buscarletra(int tam_array, int *morse_array) pasándole como
    // parámetros el tamaño del array y el array donde se almacena la letra
    char letra = buscarletra(tamano, morse_array);
    // Comprueba que el valor de la letra no sea ' ' ya que esto se debe a
    // que no ha entrado en ningún condicional
    if (letra == ' '){
      Serial.println(" El valor introducido es incorrecto");
    } else {
      //Serial.print("  -->  ");    // Muestra por pantalla "  -->  "
      //Serial.println(letra);      // Muestra por pantalla la letra obtenida
      Serial.print(letra);      // Muestra por pantalla la letra obtenida
    }
    
    delay(500);                   // Se realiza una espera de 0,5 segundo.
                                  // Para asegurarnos de que solo se realiza
                                  // una vez el condicional al pulsar el
                                  // botón fin de letra
    tamano = 0;                   // Se vuelve a asignar el valor 0 al
                                  // tamaño del array para poder escribir de
                                  // nuevo otra letra
    for(int i = 0; i < TAM; i++){ // Se vuelve a asignar el valor 0 al array
                                  // para poder escribir de nuevo otra letra
      morse_array[i] = 0;
    }
  }
}
