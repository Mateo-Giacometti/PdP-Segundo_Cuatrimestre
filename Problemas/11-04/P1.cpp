#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Report;

// headers
class Transaction {
  protected:
    int amount;
    Transaction( int amount ): amount( amount ) {}
  public:
    int value() {  return amount; }
    virtual int affectBalance() = 0;
    virtual void addToReport( Report & ) = 0;
};
class Deposit: public Transaction {
  public:
    Deposit( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return value(); }
    void addToReport( Report & report );
};
class Withdraw: public Transaction {
  public:
    Withdraw( int amount ) : Transaction( amount ) {}
    int affectBalance() {   return -value(); }
    void addToReport( Report & report );
};
class Accountable {
  public:
    virtual int balance() = 0;
    virtual void reportOn( Report & ) = 0;
};
class Account: public Accountable {
  private:
    vector<Transaction*> transactions;
  public:
    int balance();
    void deposit( int amount );
    void withdraw( int amount );
    void reportOn( Report & ); 
};
class Portfolio : public Accountable {
  private:
    vector<Accountable*> accounts;
  public:
    void add( Accountable* anAccount );
    int balance();  
    void reportOn( Report & ); 
};
class Report {
  protected:
    vector<string>  report;
  public:
    virtual void addDeposit( Deposit* aDeposit ) {};
    virtual void addWithdraw( Withdraw* aWithdraw ) {};
    virtual void addPortfolio( Portfolio* anAccountable ) {};
    virtual void addAccount( Account* anAccountable ) {};

    vector<string> reportFor( Accountable &); 
};
class DetailedReport : public Report {
  public:
    void addDeposit( Deposit* aDeposit );
    void addWithdraw( Withdraw* aWithdraw );
    void addPortfolio( Portfolio* anAccountable );
    void addAccount( Account* anAccountable );
};
class HeadersReport : public Report {
  public:
    void addPortfolio( Portfolio* anAccountable );
    void addAccount( Account* anAccountable );
};

// cpp
vector<string> Report::reportFor( Accountable & anAccountable ) {
    anAccountable.reportOn( *this );
    return report;
}
void DetailedReport::addAccount( Account* anAccountable ) {
    report.emplace_back( "Cuenta: (" + to_string( anAccountable->balance() ) + ")" );
}
void DetailedReport::addPortfolio( Portfolio* anAccountable ) {
    report.emplace_back( "Portfolio: (" + to_string( anAccountable->balance() ) + ")" );
}
void DetailedReport::addDeposit( Deposit* aDeposit ) {
    report.emplace_back( "deposito de " + to_string( aDeposit->value() ) );
}
void DetailedReport::addWithdraw( Withdraw* aWithdraw ){
    report.emplace_back( "retiro de " + to_string( aWithdraw->value() ) );
}
void HeadersReport::addAccount( Account* anAccountable ) {
    report.emplace_back( "Cuenta: (" + to_string( anAccountable->balance() ) + ")" );
}
void HeadersReport::addPortfolio( Portfolio* anAccountable ) {
    report.emplace_back( "Portfolio: (" + to_string( anAccountable->balance() ) + ")" );
}

void Deposit::addToReport( Report & report) {  report.addDeposit( this ); }
void Withdraw::addToReport( Report & report) {  report.addWithdraw( this ); }

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
void Account::reportOn( Report &report ) { 
    report.addAccount( this );
    for (auto *each : transactions) { 
        each->addToReport( report );
    }
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
void Portfolio::reportOn( Report &report ) { 
    report.addPortfolio( this );
    for (auto *each : accounts) { 
        each->reportOn( report );
    }
}
ostream& operator<<(ostream& stream, Portfolio& p) {
    // for (string line : (new HeadersReport())->reportFor( p ) ) { 
    for (string line : (new DetailedReport())->reportFor( p ) ) { 
    // for (string line : (new NiceReport())->reportFor( p ) ) { 
        stream << line << endl;
    }
    return stream;
}
// main
void testAccount() {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (10)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "deposito de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 2 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (0)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "retiro de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 3 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*cuenta)).front() == "Cuenta: (0)" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).back() == "retiro de 10" );
    assert( ((new DetailedReport())->reportFor(*cuenta)).size() == 3 );

    cout << "Account ok " << endl;
    delete cuenta;
}

int main(void) {
    testAccount();
    Portfolio *portfolio = new Portfolio();
    assert( portfolio->balance() == 0 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (0)" );

    Account *cuenta = new Account();
    cuenta->deposit( 10 );
    portfolio->add( cuenta );
    assert( portfolio->balance() == 10 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (10)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "deposito de 10" );

    Portfolio *inner = new Portfolio();
    Account *other = new Account();
    other->deposit( 5 );
    inner->add( other );
    portfolio->add( inner );
    assert( portfolio->balance() == 15 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (15)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "deposito de 5" );

    other->withdraw(3);
    assert( portfolio->balance() == 12 );
    assert( ((new DetailedReport())->reportFor(*portfolio)).front() == "Portfolio: (12)" );
    assert( ((new DetailedReport())->reportFor(*portfolio)).back() == "retiro de 3" );

    Portfolio *sub = new Portfolio();
    Account *subOther = new Account();
    subOther->deposit( 15 );
    sub->add( subOther );
    inner->add( sub );

    cout << endl << *portfolio << endl;

    cout << "Portfolio ok " << endl;

    delete cuenta;
    delete portfolio;
    delete inner;
    delete other;
    delete sub;
    delete subOther;

    return 0;
}
