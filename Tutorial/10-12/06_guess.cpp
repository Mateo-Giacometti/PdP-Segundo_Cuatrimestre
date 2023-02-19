#include <iostream>
#include <string>

using namespace std;

int main(void) {
    srand(time(NULL));

    int valToGuess = rand() % 100;
    int attempt = -1;

    cout << "<< Guess me >>" << endl;

    while (attempt != valToGuess) {
        cout << "please guess: ";
        cin >> attempt;

        if ( attempt > valToGuess ) {
            cout << " too high! " << endl;
        }
        if ( attempt < valToGuess ) {
            cout << " too low! " << endl;
        }
    }

    cout << "you nailed!" << endl;

    return 0;
}
