#include <stdio.h>

int main(void)
{
    int a;

    a = 103;
    printf(">>> a: %i\n", a);

    if ((a % 2) != 0) {
        puts("a es impar");
    } else {
        puts("a es par");
        if ((a % 4) == 0) {
            puts("y también es múltiplo de 4");
        }
    }

    a = 10;
    printf(">>> a: %i\n", a);

    if ((a % 2) != 0) {
        puts("a es impar");
    } else {
        puts("a es par");
        if ((a % 4) == 0) {
            puts("y también es múltiplo de 4");
        }
    }

    a = 12;
    printf(">>> a: %i\n", a);

    if ((a % 2) != 0) {
        puts("a es impar");
    } else {
        puts("a es par");
        if ((a % 4) == 0) {
            puts("y también es múltiplo de 4");
        }
    }

    return 0;
}
