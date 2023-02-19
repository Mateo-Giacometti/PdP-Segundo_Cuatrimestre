#include <stdio.h>

int main(void)
{
    int a, b, c;
    char x;
    unsigned short i, j;

    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(short): %lu\n", sizeof(short));
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("sizeof(long int): %lu\n", sizeof(long int));

    /* Operadores:
     *  x++, ++x, --x, x--
     *  +=, *=, /=, -=
     *  %=
     */
    a = 103;
    b = a + 15;
    c = b / 7;
    printf("a: %i\nb: %i\nc: %i\n", a, b, c);

    a /= 10;
    ++b;
    c *= b;
    printf("a: %i\nb: %i\nc: %i\n", a, b, c);

    if ((a % 2) != 0) {
        puts("a es impar");
    } else {
        puts("a es par");
        if ((a % 4) == 0) {
            puts("y también es múltiplo de 4");
        }
    }

    puts("Iterando con un while");
    i = 0;
    while (i < 5) {
        printf("%i\n", i);
        i += 1;
    }

    puts("Iterando con un for");
    for (i = 0, j = 0; i < 5; i++, j++) {
        printf("%i, %i\n", i, j);
    }


    return 0;
}
