#include <iostream>
#include <string>
#include <cmath>

/*
Analice el siguiente programa y explique qué se hace en cada paso. Si su
programa no logra ejecutar la última línea de comando, quítela (esto varía
de un sistema operativo a otro) y evalúe que es lo que puede ocasionar el
problema.
*/

using namespace std;

int main()
{
    char c = 'A';
    int i = 3, j = 1, m = 0;
    bool p = false, q = true;
    cout << c << " is integer value " << int(c)
    << " and !'A' is " << !c << endl;
    cout << "i = " << i << ", !i = " << !i << endl;
    cout << "!!i = " << !!i << ", !m = " << !m
    << endl;
    cout << "p = " << p << ", q = " << q << endl;
    cout << "!p = " << !p << ", !q = " << !q
    << endl;
    cout << "!(i + j) || m = " << (!(i + j) || m)
    << endl;
    cout << "q || (j / m) = " << (q || (j / m))
    << endl;
    cout << "(j / m) || q = " << ((j / m) || q)
    << endl;

    return EXIT_SUCCESS;
}