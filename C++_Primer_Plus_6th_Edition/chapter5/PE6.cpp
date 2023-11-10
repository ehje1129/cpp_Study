#include <iostream>
#include <string>

using namespace std;
const int MONTH = 12;
const int YEAR = 3;

int main()
{
    string month[MONTH] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int sales[YEAR][MONTH];
    int sum[YEAR] {0};
    for(int i=0; i<YEAR; i++){
        for(int j=0; j<MONTH; j++){
            cout << "Enter the sales of " << i+1 << " year " << month[j] << ": ";
            cin >> sales[i][j];
        }
    }
    for(int i=0; i<YEAR; i++){
        for(int j=0; j<MONTH; j++){
        cout << "The sales of " << i+1 << " year " << month[j] << " is " << sales[i][j] << endl;
        sum[i] += sales[i][j];
        }
    }
    for(int i=0; i<YEAR; i++){
        cout << "The total sales of " << i+1 <<" year is " << sum[i] << endl;
    }
    return 0;
}