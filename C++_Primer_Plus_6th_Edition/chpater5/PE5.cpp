#include <iostream>
#include <string>

using namespace std;
const int MONTH = 12;

int main()
{
    string month[MONTH] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int sales[MONTH];
    int sum=0;
    for(int i=0; i<MONTH; i++){
        cout << "Enter the sales of " << month[i] << ": ";
        cin >> sales[i];
    }
    for(int i=0; i<MONTH; i++){
        cout << "The sales of " << month[i] << " is " << sales[i] << endl;
        sum += sales[i];
    }
    cout << "The total sales is " << sum;
    return 0;
}