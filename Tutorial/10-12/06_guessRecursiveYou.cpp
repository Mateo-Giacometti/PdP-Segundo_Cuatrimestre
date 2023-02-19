#include <iostream>
#include <string>

using namespace std;


int guessMe( int min, int max ) {
    string response; 
    int guess;

    cout << "( " << min << " - " << max << " )" << endl;

    guess = min + ((max - min) / 2);

    cout << "Your number is: " << guess << "? (Yes, too Low, too High): ";
    cin >> response;

    if ( response == "Y" ) {
       return guess;
    }
 
    if ( ( max - min ) <= 3 ) {
        if ( response == "L" ) {
            return guess + 1;
        } else {
            return guess - 1;
        }
    } 

    if ( response == "L" ) {
        return guessMe( guess, max );
    }

    if ( response == "H" ) {
        return guessMe( min, guess );
    }

    return 0;

}

int main(void) {

    cout << "<<Guess You >>" << endl;
    cout << "Think a number from 1 up to 100" << endl;

    int guess = guessMe( 0, 100 );

    cout << "Your number is: " << guess << "!";

    return 0;
}

