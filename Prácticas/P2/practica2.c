// Práctica 2 - Uso de bibliotecas de programación de interfaces de usuario en modo texto
// Realizado por: Arturo Alonso Carbonero
// Grupo: 4ºA
// Curso: 21-22
// Compilación -> gcc practica2.c -lncurses -o practica2

#include <curses.h>
#include <unistd.h>

#define JUGADOR "|"
#define BOLA "o"
#define DELAY 90000

// Pares de colores
#define MARCADOR 2
#define CAMPO 1
#define JB 3

int main(int argc, char *argv[]){
  // Ventana
  int rows, cols; // Tamaño de la ventana

  // Bola
  bool diagonalDchaArriba=true, diagonalIzdaArriba=false; // Direcciones
  bool diagonalDchaAbajo=false, diagonalIzdaAbajo=false; // Direcciones
  int x=0, y=0; // Coordenadas actuales de la bola
  int sigX=0, sigY=0; // Coordenadas siguientes
  int yCentral=0, xCentral=0; // Coordenadas centrales

  // Jugadores
  int puntosJ1=0, puntosJ2=0; // Puntos de los jugadores
  int yJ1=10, yJ2=27; // Posición al inicio
  int xJ1=3, xJ2=96; // Posición permanente de los jugadores en el eje X
  int ch=0; // Carácter a leer para el moviemiento de los jugadores

  // Inicio de ncurses
  initscr();
  noecho();
  curs_set(FALSE);

  start_color();
  init_pair(CAMPO, COLOR_WHITE, COLOR_BLACK);
  init_pair(MARCADOR, COLOR_BLUE, COLOR_BLACK);
  init_pair(JB, COLOR_CYAN, COLOR_BLACK);
  clear();
 	refresh();

  // Tamaño de la ventana
  getmaxyx(stdscr, rows, cols); // 37 (filas) x 100 (columnas) para la máquina utilizada
  yCentral=rows/2;
  xCentral=cols/2;

  // ------------------------------------------------------------------------ //

  // Pantalla inicial con los controles y las normas del juego

  // Pantalla inicial
  WINDOW *window=newwin(rows, cols, 0, 0);
  wbkgd(window, COLOR_PAIR(CAMPO));
  box(window, '|', '-');

  // Texto generado en terminal con el comando 'figlet' (retirando '\' y añadiendo '_' arriba)
  mvprintw(2, 37, " ____   ___ __  __   ___");
  mvprintw(3, 37, "|  _   / _  |   | |/ ___|");
  mvprintw(4, 37, "| |_) | | | | | | | |  _");
  mvprintw(5, 37, "|  __/| |_| | |   | |_| |");
  mvprintw(6, 37, "|_|     ___/|_| |_| ____|");

  // Controles
  mvprintw(10, 45, "CONTROLES");
  mvprintw(12, 45, "Jugador 1");
  mvprintw(14, 43.5, "Arriba -> w");
  mvprintw(15, 43.5, "Abajo  -> S");
  mvprintw(18, 45, "Jugador 2");
  mvprintw(20, 43.5, "Arriba -> u");
  mvprintw(21, 43.5, "Abajo  -> j");

  // Reglas
  mvprintw(26, 47, "REGLAS");
  mvprintw(28, 30, "- Si la bola toca la parte izquierda (para J1)");
  mvprintw(29, 30, "o derecha (para J2), punto para el rival.");
  mvprintw(30, 30, "- Gana el primero que llegue a 5 puntos.");

  // Nombre
  mvprintw(35, 33, "Realizado por: Arturo Alonso Carbonero");
  wrefresh(window);

  getch();

  // ------------------------------------------------------------------------ //

  // Pantalla de juego
  WINDOW *window2=newwin(rows, cols, 0, 0);
  wbkgd(window2, COLOR_PAIR(CAMPO));
  box(window2, '|', '-');

  wattron(window2, COLOR_PAIR(JB));
  mvwprintw(window2, yCentral, xCentral, BOLA);
  wattroff(window2, COLOR_PAIR(JB));

  wrefresh(window2);
  getch();

  // ------------------------------------------------------------------------ //

  // Código fuente del juego

  // Posiición inicial de la bola en el centro de la pantalla
  y=yCentral;
  x=xCentral;
  sigY=y;
  sigX=x;

  // Bucle del juego. Termina cuando un jugador obtiene 5 puntos
  while(puntosJ1<5 && puntosJ2<5){
    box(window2, '|', '-'); // Borde del campo

    wattron(window2, COLOR_PAIR(JB));
    mvwprintw(window2, y, x, BOLA);
    mvwprintw(window2, yJ1, xJ1, JUGADOR);
    mvwprintw(window2, yJ2, xJ2, JUGADOR);
    wattroff(window2, COLOR_PAIR(JB));

    wrefresh(window2);

    // Moviemiento de jugadores
    ch=wgetch(window2); // Leer carácter de teclado
    nodelay(window2, true); // getch() sin pausa
    switch(ch){
      case 'w':
        if(yJ1>1){
          wattron(window2, COLOR_PAIR(JB));
          mvwprintw(window2, yJ1--, xJ1, JUGADOR); // Moviemiento
          mvwprintw(window2, yJ1+1, xJ1, " "); // Aspecto
          mvwprintw(window2, yJ1+1, xJ1+1, " "); // Aspecto
          wattroff(window2, COLOR_PAIR(JB));
          wrefresh(window2);
        }
        break;
      case 's':
        if(yJ1<rows-2){
          wattron(window2, COLOR_PAIR(JB));
          mvwprintw(window2, yJ1++, xJ1, JUGADOR); // Moviemiento
          mvwprintw(window2, yJ1-1, xJ1, " "); // Aspecto
          mvwprintw(window2, yJ1-1, xJ1+1, " "); // Aspecto
          wattroff(window2, COLOR_PAIR(JB));
          wrefresh(window2);
        }
        break;
      case 'u':
        if(yJ2>1){
          wattron(window2, COLOR_PAIR(JB));
          mvwprintw(window2, yJ2--, xJ2, JUGADOR); // Moviemiento
          mvwprintw(window2, yJ2+1, xJ2, " "); // Aspecto
          mvwprintw(window2, yJ2+1, xJ2-1, " "); // Aspecto
          wattroff(window2, COLOR_PAIR(JB));
          wrefresh(window2);
        }
        break;
      case 'j':
        if(yJ2<rows-2){
          wattron(window2, COLOR_PAIR(JB));
          mvwprintw(window2, yJ2++, xJ2, JUGADOR); // Moviemiento
          mvwprintw(window2, yJ2-1, xJ2, " "); // Aspecto
          mvwprintw(window2, yJ2-1, xJ2-1, " "); // Aspecto
          wattroff(window2, COLOR_PAIR(JB));
          wrefresh(window2);
        }
        break;
    }

    usleep(DELAY);

    // Sentido y rebote
    // Dependiendo de qué variable de dirección esté activada (true)
    // la bola tomará una dirección y sentido u otros.

    // Sentido
    if(diagonalDchaArriba){
      x=sigX; y=sigY;
      sigX++; sigY--;
    }else if(diagonalDchaAbajo){
      x=sigX; y=sigY;
      sigX++; sigY++;
    }else if(diagonalIzdaArriba){
      x=sigX; y=sigY;
      sigX--; sigY--;
    }else{
      x=sigX; y=sigY;
      sigX--; sigY++;
    }

    mvwprintw(window2, yCentral, xCentral, " ");
    wrefresh(window2);

    // Rebotes
    // Dependiendo de la dirección actual y de dónde rebote (techo, suelo o jugador)
    // cambia a la dirección pertinente.

    // Rebote diagonal (siempre 45º)
    if(diagonalIzdaArriba && y==1){ // Techo
      diagonalIzdaArriba=false;
      diagonalIzdaAbajo=true;
    }else if(diagonalDchaArriba && y==1){ // Techo
      diagonalDchaArriba=false;
      diagonalDchaAbajo=true;
    }else if(diagonalDchaAbajo && y==36){ // Suelo
      diagonalDchaAbajo=false;
      diagonalDchaArriba=true;
    }else if(diagonalIzdaAbajo && y==36){ // Suelo
      diagonalIzdaAbajo=false;
      diagonalIzdaArriba=true;
    }else if(diagonalIzdaArriba && (y==yJ1 && x==xJ1+1)){ // Jugador 1
      diagonalIzdaArriba=false;
      diagonalDchaArriba=true;
      mvwprintw(window2, y+1, x+1, " "); // Aspecto al rebotar
      wrefresh(window2);
    }else if(diagonalIzdaAbajo && (y==yJ1 && x==xJ1+1)){ // Jugador 1
      diagonalIzdaAbajo=false;
      diagonalDchaAbajo=true;
      mvwprintw(window2, y-1, x+1, " "); // Aspecto al rebotar
      wrefresh(window2);
    }else if(diagonalDchaArriba && (y==yJ2 && x==xJ2-1)){ // Jugador 2
      diagonalDchaArriba=false;
      diagonalIzdaArriba=true;
      mvwprintw(window2, y+1, x-1, " "); // Aspecto al rebotar
      wrefresh(window2);
    }else if(diagonalDchaAbajo && (y==yJ2 && x==xJ2-1)){ // Jugador 2
      diagonalDchaAbajo=false;
      diagonalIzdaAbajo=true;
      mvwprintw(window2, y-1, x-1, " "); // Aspecto al rebotar
      wrefresh(window2);
    }

    // Solución de aspectos
    // Muestra un espacio (" ") en la posición anterior de la bola para que no
    // se muetre un rastro de la misma.

    if(sigX<x && diagonalIzdaArriba){
      if(x-1==0){
        mvwprintw(window2, y+1, x+1, " ");
      }else{
        mvwprintw(window2, y+1, x+1, " ");
        mvwprintw(window2, y, x+2, " ");
        mvwprintw(window2, y-1, x+3, " ");

        mvwprintw(window2, yJ2, xJ2-1, " ");
      }
      wrefresh(window2);
    }else if(sigX<x && diagonalIzdaAbajo){
      if(x-1==0){
        mvwprintw(window2, y-1, x+1, " ");
      }else{
        mvwprintw(window2, y-1, x+1, " ");
        mvwprintw(window2, y, x+2, " ");
        mvwprintw(window2, y+1, x+3, " ");

        mvwprintw(window2, yJ2, xJ2-1, " ");
      }
      wrefresh(window2);
    }else if(sigX>x && diagonalDchaArriba){
      if(x+1==cols-1){
        mvwprintw(window2, y+1, x-1, " ");
      }else{
        mvwprintw(window2, y+1, x-1, " ");
        mvwprintw(window2, y, x-2, " ");
        mvwprintw(window2, y-1, x-3, " ");

        mvwprintw(window2, yJ1, xJ1+1, " ");
      }
    }else if(sigX>x && diagonalDchaAbajo){
      if(x+1==cols-1){
        mvwprintw(window2, y-1, x-1, " ");
      }else{
        mvwprintw(window2, y-1, x-1, " ");
        mvwprintw(window2, y, x-1, " ");
        mvwprintw(window2, y+1, x-1, " ");

        mvwprintw(window2, yJ1, xJ1+1, " ");
      }
    }

    // Conteo de puntos
    if(x==cols-1){
      puntosJ1++;
      y=yCentral; x=xCentral;
      sigY=y; sigX=x;
      getch();
    }else if(x==0){
      puntosJ2++;
      y=yCentral; x=xCentral;
      sigY=y; sigX=x;
      getch();
    }

    // Mostrar marcador
    wattron(window2, COLOR_PAIR(MARCADOR));
    mvwprintw(window2, 2, 25, "J1: ");
    char ptosJ1[50]; // Convertir int en const char*
    sprintf(ptosJ1, "%d", puntosJ1); // --^
    mvwprintw(window2, 2, 29, ptosJ1);

    mvwprintw(window2, 2, 70, "J2: ");
    char ptosJ2[50];
    sprintf(ptosJ2, "%d", puntosJ2);
    mvwprintw(window2, 2, 74, ptosJ2);
    wattroff(window2, COLOR_PAIR(MARCADOR));

    wrefresh(window2);

    // Fin del juego
    if(puntosJ1==5 || puntosJ2==5){
      getch();
    }
  }

  // ------------------------------------------------------------------------ //

  // Ventana de victoria
  WINDOW *window3=newwin(rows, cols, 0, 0);
  wbkgd(window3, COLOR_PAIR(1));
  box(window3, '|', '-');
  if(puntosJ1>puntosJ2){
    mvwprintw(window3, 18, 37, "¡El jugador J1 ha ganado!");
    wrefresh(window3);
  }else{
    mvwprintw(window3, 18, 37, "¡El jugador J2 ha ganado!");
    wrefresh(window3);
  }
  getch();

  // ------------------------------------------------------------------------ //

  // Ventana de salida
  WINDOW *window4=newwin(rows, cols, 0, 0);
  wbkgd(window4, COLOR_PAIR(1));
  box(window4, '|', '-');
  mvwprintw(window4, 18, 37, "Pulsa una tecla para salir");
  wrefresh(window4);

  // ------------------------------------------------------------------------ //

  // Fin del programa
  getch();
  endwin();
  return 0;
}
