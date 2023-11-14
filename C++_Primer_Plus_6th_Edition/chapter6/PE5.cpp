#include <iostream>

using namespace std;

int main()
{
    double income, tax;
    cout << "Please Enter your income: ";
    while (cin >> income && income >= 0){
        if (income > 35000)
            tax = (income-35000)*0.2 + 20000*0.15 + 10000*0.1;
        else if (income > 15000)
            tax = (income-15000)*0.15 + 10000*0.1;
        else if (income > 5000)
            tax = (income-5000)*0.1;
        else
            tax = 0;
        cout << "tax: " << tax << " tvarps" << endl;
    }
    return 0;
}