#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Transaction {
  protected:
    int amount;
        Transaction( int amount ): amount( amount ) {}
  public:
    ~Transaction();
    int value() {  return amount; }
    virtual bool isDeposit() = 0;
    virtual int affectBalance() = 0;
    virtual string affectReport() = 0;
};

class Deposit: public Transaction {
  public:
    Deposit( int amount ) : Transaction( amount ) {}
    bool isDeposit() {      return true; };
    int affectBalance() {   return value(); }
    string affectReport() { return "deposito de " + to_string( value() ); }
};

class Withdraw: public Transaction {
  public:
    Withdraw( int amount ) : Transaction( amount ) {}
    bool isDeposit() {      return false; };
    int affectBalance() {   return -value(); }
    string affectReport() { return "retiro de " + to_string( value() ); }
};

class Account {
  private:
    vector<Transaction*> transactions;
  public:
    Account();
    ~Account();
    int balance();
    void deposit( int amount );
    void withdraw( int amount );
    vector<string> report();
};

Account::Account() {}
Account::~Account() {}
int Account::balance(){ 
    int total = 0;
    for (auto *each : transactions) {
        total += each->affectBalance();
    }
    return total;
}
void Account::deposit( int amount ){ 
    transactions.emplace_back( new Deposit( amount ) );
}
void Account::withdraw( int amount ){ 
    if( ( balance() - amount ) >= 0 ) {
        transactions.emplace_back( new Withdraw( amount ) );
    } 
}
vector<string> Account::report(){ 
    vector<string>  report;
    for (auto *each : transactions) { 
        report.emplace_back( each->affectReport() );
    }
    return report;
}

int main(void) {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
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

    cout << "ok " << std::endl;

    delete cuenta;

    return 0;
}