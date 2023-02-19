#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(short): %lu\n", sizeof(short));
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("sizeof(long int): %lu\n", sizeof(long int));

    puts("");
    printf("| ** Tipo **        | ** Tamaño ** | ** Rango **         |\n");
    printf("| char              | %lu B          | -128 / 127          |\n", sizeof(char));
    printf("| unsigned char     | %lu B          | 0 / 255             |\n", sizeof(unsigned char));
    printf("| short             | %lu B          | -32768 / 32767      |\n", sizeof(short));
    printf("| unsigned short    | %lu B          | 0 / 65535           |\n", sizeof(unsigned short));
    printf("| int               | %lu B          | -2^31 / 2^31 - 1    |\n", sizeof(int));
    printf("| unsigned int      | %lu B          | 0 / 2^32 - 1        |\n", sizeof(unsigned int));
    printf("| long int          | %lu B          | -2^63 / 2^63 - 1    |\n", sizeof(long int));
    printf("| unsigned long int | %lu B          | 0 / 2^64 - 1        |\n", sizeof(unsigned long int));
    printf("| float             | %lu B          | +/- 1.8x10^(+/-38)  |\n", sizeof(float));
    printf("| double            | %lu B          | +/- 1.8x10^(+/-308) |\n", sizeof(double));

    /* Leer: man 3 printf, o los secretos de printf */
    puts("");
    printf("| ** Tipo **        | ** Tamaño ** |                 ** Rango **                 |\n");
    printf("| char              | %lu B          | %20i / %-20i |\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("| unsigned char     | %lu B          | %20u / %-20u |\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("| short             | %lu B          | %20hi / %-20hi |\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("| unsigned short    | %lu B          | %20hu / %-20hu |\n", sizeof(unsigned short), 0, USHRT_MAX);
    printf("| int               | %lu B          | %20i / %-20i |\n", sizeof(int), INT_MIN, INT_MAX);
    printf("| unsigned int      | %lu B          | %20u / %-20u |\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("| size_t            | %lu B          | %20zu / %-20zu |\n", sizeof(size_t), (size_t) 0, SIZE_MAX);
    printf("| long int          | %lu B          | %20li / %-20li |\n", sizeof(long int), LONG_MIN, LONG_MAX);
    printf("| unsigned long int | %lu B          | %20lu / %-20lu |\n", sizeof(unsigned long int), 0UL, ULONG_MAX);
    printf("| float             | %lu B          | +/-%17g / +/-%-17g |\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("| double            | %lu B          | +/-%17g / +/-%-17g |\n", sizeof(double), DBL_MIN, DBL_MAX);

    return 0;
}
