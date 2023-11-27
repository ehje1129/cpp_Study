#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << num << "! = " << factorial(num) << endl;
    return 0;
}

int factorial(int n){
    if (n == 0) return 1;
    else return factorial(n-1)*n;
}