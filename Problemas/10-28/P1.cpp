#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// headers
class Transaction {
  protected:
    int amount;
    Transaction( int amount ): amount( amount ) {}
  public:
    ~Transaction();
    int value() {  return amount; }
    virtual int affectBalance() = 0;
    virtual string affectReport() = 0;
};
class Deposit: public Transaction {
  public:
    Deposit( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return value(); }
    string affectReport() { return "deposito de " + to_string( value() ); }
};
class Withdraw: public Transaction {
  public:
    Withdraw( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return -value(); }
    string affectReport() { return "retiro de " + to_string( value() ); }
};
class Accountable {
  public:
    virtual int balance() = 0;
    virtual vector<string> report() = 0;
};
class Account: public Accountable {
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
class Portfolio : public Accountable {
  private:
    vector<Accountable*> accounts;
  public:
    void add( Accountable* anAccount );
    int balance();  
    vector<string> report();
};

// cpp
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
int Portfolio::balance(){ 
    int total = 0;
    for (auto *each : accounts) {
        total += each->balance();
    }
    return total;
}
void Portfolio::add( Accountable* anAccount ){ 
    accounts.emplace_back( anAccount );
}
vector<string> Portfolio::report(){ 
    vector<string>  report;
    report.emplace_back( "Portfolio: (" + to_string( balance() ) + ")" );
    for (auto *each : accounts) { 
        vector<string> innerReport = each->report();
        for (string inner : innerReport) { 
            report.emplace_back( inner );
        }
    }
    return report;
}
// main
void testAccount() {
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

    cout << "Account ok " << endl;
    delete cuenta;
}

int main(void) {
    testAccount();
    Portfolio *portfolio = new Portfolio();
    assert( portfolio->balance() == 0 );
    assert( portfolio->report().front() == "Portfolio: (0)" );

    Account *cuenta = new Account();
    cuenta->deposit( 10 );
    portfolio->add( cuenta );
    cout << "Portolio ok " << endl;
    assert( portfolio->balance() == 10 );
    assert( portfolio->report().front() == "Portfolio: (10)" );
    assert( portfolio->report().back() == "deposito de 10" );

    Portfolio *inner = new Portfolio();
    Account *other = new Account();
    other->deposit( 5 );
    inner->add( other );
    
    portfolio->add( inner );
    assert( portfolio->balance() == 15 );



    cout << "Portolio ok " << endl;

    delete cuenta;
    delete portfolio;
    delete inner;
    delete other;
    
    return 0;
}
