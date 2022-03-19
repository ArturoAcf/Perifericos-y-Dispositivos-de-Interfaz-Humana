// Práctica 1 - Entrada y salida utilizando interrupciones con lenguaje C
// Realizado por: Arturo Alonso Carbonero
// Grupo: 4ºA
// Curso: 21-22

#include <stdio.h>
#include <dos.h>

int colorFondo; // Variable global para el color de fondo
int colorTexto; // Variable global para el color de primer plano

// -------------------------------------------------------------------------- //

/*
  Estructura de int86()

  - intno -> Número de interrupción a ejecutar
  - inregs -> Valores de los registros antes de la llamada
  - outregs -> Valores de los registros tras ser ejecutada la rutina correspondiente

  int int86(int intno, union REGS *inregs, union REGS *outregs);

  union REGS{
    struct WORDREGS x;
    struct BYTEREGS h;
  };

  struct BYTEREGS{
    unsigned char al, ah, bl, bh;
    unsigned char cl, ch, dl, dh;
  };
  struct WORDREGS{
    unsigned int ax, bx, cx, dx;
    unsigned int si, di, cflag, flags;
  };
*/

// -------------------------------------------------------------------------- //

// Función para pausar

void pausa(){
  union REGS inregs, outregs;

  inregs.h.ah=8;

  int86(0x21, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// - - - Requisitos mínimos - - - //

// gotoxy() -> Función para colocar el cursor en una posición determinada

void gotoxy(int x, int y){
  union REGS inregs, outregs;

  inregs.h.ah=0x02;
  inregs.h.bh=0x00;
  inregs.h.dh=x; // Coordenada x
  inregs.h.dl=y; // Coordenada y

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// setcursortype() -> Función para fijar el aspecto del cursor (INVISIBLE, NORMAL y GRUESO)

void setcursortype(int tipo_cursor){
  union REGS inregs, outregs;
  inregs.h.ah=0x01;

  switch(tipo_cursor){
    case 0: // Invisible
      inregs.h.ch=010;
      inregs.h.cl=000;
      break;
    case 1: // Normal
      inregs.h.ch=010;
      inregs.h.cl=010;
      break;
    case 2: // Grueso
      inregs.h.ch=000;
      inregs.h.cl=010;
      break;
  }

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// setvideomode() -> Función para fijar el modo de vídeo deseado

void setvideomode(int x){
  union REGS inregs, outregs;

  inregs.h.ah=0x00;
  inregs.h.al=x;

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// getvideomode() -> Función para obtener el modo de vídeo actual

void getvideomode(){
  union REGS inregs, outregs;
  int modo;
  int numColumnas;

  inregs.h.ah=0xF;

  int86(0x10, &inregs, &outregs);

  modo=outregs.h.al; // Modo actual
  numColumnas=outregs.h.ah; // Número de columnas en los modos de texto

  if(modo<=3 || modo==7){ // Según la tabla
    printf("Texto");
  }else{
    printf("Grafico");
  }
}

// -------------------------------------------------------------------------- //

// textcolor() -> Función para modificar el color de primer plano con el que se mostrarán los caracteres

void textcolor(int colorTexto){
  union REGS inregs, outregs;

  inregs.h.ah=0x09;
  inregs.h.al=97; // 'a'
  inregs.h.bl=colorTexto;
  inregs.h.bh=0x00;
  inregs.x.cx=10; // Número de repeticiones

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// textbackground() -> Función para modificar el color de fondo con el que se mostrarán los caracteres

void textbackground(int colorTexto, int colorFondo){
  union REGS inregs, outregs;
  int color=colorFondo << 4 | colorTexto;

  inregs.h.ah=0x09;
  inregs.h.al=98; // 'b'
  inregs.h.bl=color;
  inregs.h.bh=0x00;
  inregs.x.cx=10; // Número de repeticiones

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// clrscr() -> Borrar toda la pantalla

void clrscr(){
  union REGS inregs, outregs;

  inregs.h.ah=0x15;
  int86(0x10, &inregs, &outregs);
  inregs.h.ah=0x00;
  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// cputchar() -> Escribe un carácter en pantalla con el color actual

void cputchar(char c){
  union REGS inregs, outregs;

  inregs.h.ah=2;
  inregs.h.dl=c;

  int86(0x21, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// getche() -> Obtiene un carácter de teclado y lo muestra en pantalla

int getche(){
  union REGS inregs, outregs;
  int caracter;

  inregs.h.ah=0x01;

  int86(0x21, &inregs, &outregs);

  caracter=outregs.h.al; // Código ASCII del carácter
  return caracter;
}

// -------------------------------------------------------------------------- //

// - - - Requisitos ampliados - - - //

// dibujarCuadradoModoTexto() -> Función para dibujar un cuadrado en pantalla. recibe como parámetros
//                               las coordenadas de las esquinas superior izquierda e inferior derecha
//                               del cuadrado, el color de primer plano y el color de fondo

void dibujarCuadradoModoTexto(int f1, int c1, int f2, int c2, int primerPlano, int fondo){
  union REGS inregs, outregs;

  inregs.h.ah=0x06;
  inregs.h.al=0; // Número de líneas a desplazar. Si al=0 => borra la zona
  inregs.h.bh=fondo << 4 | primerPlano; // Color para los espacios en blanco
  inregs.h.ch=f1; // Fila de la esquina superior izquierda
  inregs.h.cl=c1; // Columna de la esquina superior izquierda
  inregs.h.dh=f2; // Fila de la esquina inferior derecha
  inregs.h.dl=c2; // Columna de la esquina inferior derecha

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// modoGraficoCGA() -> Función para crear dibujos sencillos en pantalla

void modoGraficoCGA(int x, int y, int color){
  union REGS inregs, outregs;

  inregs.h.ah=0x0C;
  inregs.x.cx=x;
  inregs.x.dx=y;
  inregs.h.al=color;

  int86(0x10, &inregs, &outregs);
}

// -------------------------------------------------------------------------- //

// Función principal

int main(){
  int temp, x, y, i;

  printf("\nPulsa una tecla: ");
  temp=getche();

  printf("\nHas pulsado: ");
  cputchar((char)temp);

  printf("\nCursor invisible: ");
  setcursortype(0);
  pausa();
  printf("\nCursor normal: ");
  setcursortype(1);
  pausa();
  printf("\nCursor grueso: ");
  setcursortype(2);
  pausa();

  printf("\nCursor colocado en la posicion indicada");
  gotoxy(0x09, 0x09);
  pausa();

  printf("\nEstableciendo modo de video");
  setvideomode(0x03);
  pausa();

  printf("\nModo de video actual: ");
  getvideomode();
  pausa();

  colorFondo=1; // Azul
  colorTexto=11; // LIGHTCYAN

  printf("\nCaracteres con colores: ");
  textcolor(colorTexto);
  pausa();

  colorTexto=2; // Verde

  printf("\nCaracteres y fondo con colores: ");
  textbackground(colorTexto, colorFondo);
  pausa();

  printf("\nCuadrado cian: ");
  dibujarCuadradoModoTexto(5, 5, 20, 25, colorFondo, colorFondo);
  pausa();

  setvideomode(0x04); // Entrar en modo gráfico -> 320 (ancho) x 200 (alto)
  getvideomode();
  printf(" CGA");

  // Cubo dibujado con píxeles llamando a la función modoGraficoCGA()  /  0x02 = Rosa / 0x01 = Azul celeste

  // Cuadrado 1
  for(i=70; i<110; i++){
    modoGraficoCGA(70, i, 0x01);
    modoGraficoCGA(110, i, 0x01);
  }
  for(i=70; i<111; i++){
    modoGraficoCGA(i, 110, 0x01);
    modoGraficoCGA(i, 70, 0x01);
  }

  // Cuadrado 2
  for(i=50; i<90; i++){
    modoGraficoCGA(50, i, 0x01);
    modoGraficoCGA(90, i, 0x01);
  }
  for(i=50; i<91; i++){
    modoGraficoCGA(i, 90, 0x01);
    modoGraficoCGA(i, 50, 0x01);
  }

  // Diagonales
  for(i=50; i<71; i++){
    modoGraficoCGA(i, i, 0x01);
    modoGraficoCGA(i+40, i, 0x01);
  }
  for(i=90; i<111; i++){
    modoGraficoCGA(i, i, 0x01);
    modoGraficoCGA(i-40, i, 0x01);
  }

  pausa();
  setvideomode(0x03); // Vuelta a modo texto

  // Borrar pantalla
  clrscr();
  pausa();
  clrscr();
  printf("Pantalla borrada (pulsa enter para volver al prompt)\n");
  pausa();

  return 0;
}
