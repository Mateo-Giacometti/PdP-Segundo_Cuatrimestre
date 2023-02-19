#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef enum { Piedra, Papel, Tijera, Juego } Jugada;
typedef enum { Win, Tie, Lose, States } Resultado;

static char *moveNames[Juego] = {  [Papel] = "Papel", [Piedra] = "Piedra", [Tijera] = "Tijera" };
static char *stateNames[States] = { [Win] = "Gana", [Tie] = "Empata", [Lose] = "Pierde" };

Resultado states[Juego][States] = {
    [Piedra] = {[Piedra] = Tie,  [Tijera] = Win,  [Papel] = Lose },
    [Papel] =  {[Piedra] = Win,  [Tijera] = Lose, [Papel] = Tie  },
    [Tijera] = {[Piedra] = Lose, [Tijera] = Tie,  [Papel] = Win  }
};

Jugada find( char * jugada ) {
    for ( Jugada j = 0; j < Juego; j ++ ) {
        if ( strcmp( jugada, moveNames[ j ] ) == 0 ) {
            return j;
        }
    }
    return Juego;
} 

void test() {
    printf( "Piedra es %d\n", find( "Piedra") );
    printf( "Papel es %d\n",  find( "Papel") );
    printf( "Tijera es %d\n", find( "Tijera") );

}


int main(int argc, char** argv) {

    srand(time(0));
    if ( argc == 1 ) {
        test();
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        Jugada ia = rand() % Juego;
        printf( "Tu: %s  IA: %s ---> resultado %s\n", 
                argv[i], 
                moveNames[ ia ], 
                stateNames[ states[ find(argv[ i ]) ][ ia ] ] );
    }

}