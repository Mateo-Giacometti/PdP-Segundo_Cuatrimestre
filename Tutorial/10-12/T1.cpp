#include <vector>
#include <cstdlib>
#include <iostream>


using namespace std;

int main(void) {
    vector<string> names;

    names.reserve(3);

    names.emplace_back( "Adam" );
    names.emplace_back( "Bob" );
    names.emplace_back( "Charly" );

    //Bajo nivel
    for (int i = 0; i < names.size(); i++) {
        cout << names.at( i ) << endl;
    }

    //Alto nivel
    for (auto each = names.begin(); each != names.end(); each++) {
        cout << *each << endl;
    }

    return 0;
}