#include <iostream>
#include "stack.h"

void add(Stack & s, customer & c);
void remove(Stack & s, double & t);
void show(void);

int main() {
    using namespace std;
    char command;
    Stack s;
    customer c;
    double running_total=0;

    cout << "'a' to add customer, 'r' to remove customer, 'q' to quit program" << endl;
    cin >> command;
    cin.get();
    while(command != 'q'){
        switch (command)
        {
        case 'a':
            add(s, c);
            break;
        case 'r':
            remove(s, running_total);
            break;
        default:
            cout << "wrong command. type a, r, or q" << endl;
            break;
        }
        cin >> command;
        cin.get();
    }
}

void add(Stack & s, customer & c){
    using namespace std;
    cout << "Enter the fullname: ";
    cin.getline(c.fullname, 35);
    cout << "Enter the payment: ";
    cin >> c.payment;
    cin.get();
    if (s.push(c))
        cout << "Customer has been added successfully." << endl;
    else
        cout << "Failed to add customer. Stack is already full..." << endl;
}

void remove(Stack & s, double & t){
    using namespace std;
    customer c;
    if (s.pop(c)) {
        cout << c.fullname << " is removed" << endl;
        t+=c.payment;
    }
    else
        cout << "Stack is already empty" << endl;
    cout << "The running total is " << t << endl;
}
