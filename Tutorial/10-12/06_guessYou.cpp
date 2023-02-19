#include <iostream>
#include <string>

using namespace std;

int main(void) {

    int min = 0;
    int max = 101;
    string response; 

    cout << "<<Guess You >>" << endl;
    cout << "Think a number from 1 up to 100" << endl;

    int guess;

    while ( ( max - min ) > 2) {
        guess = min + ((max - min) / 2);

        cout << "Your number is: " << guess << "? (Yes, too Low, too High): ";
        cin >> response;

        if ( response == "L" ) {
            min = guess;
        }
        if ( response == "H" ) {
            max = guess;
        }
        if ( response == "Y" ) {
            break;
        }
        cout << "( " << min << " - " << max << " )" << endl;

    }

    if ( response == "Y" ) {
        cout << "Your number is: " << guess << "!";
    } else if ( response == "L" ) {
        cout << "Your number is: " << guess + 1 << "!";
    } else {
        cout << "Your number is: " << guess - 1 << "!";
    }

    return 0;
}

