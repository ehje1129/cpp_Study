#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number of rows: ";
    cin >> num;
    for (int i=1; i<=num; i++){
        for (int j=i; j<num; j++)
            cout << ".";
        for (int j=i; j>0; j--)
            cout << "*";
        cout << endl;
    }
    return 0;
}