#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <sstream> 

/*Modelar una cuenta bancaria. Los metodos son:
-Hacer depositos
-Hacer retiros
-Consultar balance
-Reportar*/

class Account {
  private:
    std::vector<int> transactions;
  public:
    Account();
    ~Account();
    int balance();
    void deposit(int amount);
    void withdraw(int amount);
    std::vector<std::string> report();

};

Account::Account() {}
Account::~Account() {}
int Account::balance() {
    int total = 0;
    for(auto each = transactions.begin(); each != transactions.end(); each++){
        total += *each;
    }
    if(total < 0){
        total = 0;
        return total;
    }
    else{
        return total;
    }
}
void Account::deposit(int amount) {
    transactions.emplace_back(amount);
}
void Account::withdraw(int amount) {
    transactions.emplace_back(-1 * amount);
}
std::vector<std::string> Account::report(){
    std::vector<std::string> report;

    for(auto each = transactions.begin(); each != transactions.end(); each++){
        if(*each > 0){
            report.emplace_back("deposito de " + std::to_string(*each));
        }
        else{
            report.emplace_back("retiro de " + std::to_string(-1 * *each));
        }
    }

    return report;
}

int main(void){

    Account *cuenta = new Account();
    
    assert(cuenta->balance() == 0);

    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().size() == 1 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );
    
    std::cout << "OK" << std::endl;

    delete cuenta;

    return EXIT_SUCCESS;
}