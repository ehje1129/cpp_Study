#include <iostream>
#include <string>
using namespace std;

class Account {
    private:
        string name;
        string account_num;
        double balance;

    public:
        Account(string n="ABC DEF", string acc_n="123456", double b=0);
        void show();
        void deposit(double m);
        void withdraw(double m);
};

Account::Account(string n, string acc_n, double b){
    name = n;
    account_num = acc_n;
    balance = b;
}

void Account::show(){
    cout << "Name: " << name << endl;
    cout << "Account name: " << account_num << endl;
    cout << "Balance: " << balance << endl;
}

void Account::deposit(double m){
    balance+=m;
}

void Account::withdraw(double m){
    balance-=m;
}

int main(void){
    Account a1;
    Account a2("bank account", "a987654 b321", 143.24);

    a1.show();
    a2.show();

    a2.deposit(100);
    a2.show();
    a2.withdraw(200);
    a2.show();

    return 0;
}