#include <stdio.h>

int main(void)
{
    unsigned short i, j;

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

    puts("Ciclos anidados");
    puts("    m = {");
    for (i = 0; i < 5; ++i) {
        printf("        {(%i, %i)", i, 0);
        for (j = 1; j < 9; ++j) {
            printf(", (%i, %i)", i, j);
        }
        puts("},");
    }
    puts("    };\n");

    puts("break: 1 a 100 hasta divisible por 3, por 5, y por 25");
    printf("%i", 1);
    for (i = 2; i < 100; i++) {
        printf(", %i", i);
        if (((i % 3) == 0) && ((i % 5) == 0) && ((i % 25) == 0)) {
            break;
        }
    }
    puts("\n");

    puts("continue: 0 a 100 sólo pares");
    printf("%i", 2);
    for (i = 3; i < 100; i++) {
        if (i % 2) {
            continue;
        }
        printf(", %i", i);
    }
    puts("\n");

    return 0;
}
