#include <iostream>
#include "sales.h"

void SALES::setSales(Sales & s, const double ar[], int n){
    int num = n<QUARTERS ? n:QUARTERS;
    double min = ar[0];
    double max = ar[0];
    double sum = 0;
    for (int i=0; i<QUARTERS; i++){
        if (i<num) {
            s.sales[i] = ar[i];
            min = min<ar[i] ? min:ar[i];
            max = max>ar[i] ? max:ar[i];
            sum += ar[i];
        }
        else s.sales[i] = 0;
    }
    s.max = max;
    s.min = min;
    s.average = sum/num;
}

void SALES::setSales(Sales & s){
    using namespace std;
    double ar[QUARTERS];
    for (int i=0; i<QUARTERS; i++){
        cout << "Enter the sales of quarter #" << i+1 << ": ";
        cin >> ar[i];
    }
    setSales(s, ar, QUARTERS);
}

void SALES::showSales(const Sales & s){
    using namespace std;
    cout << "Sales:";
    for (int i=0; i<QUARTERS; i++) cout << " " << s.sales[i];
    cout << endl;
    cout << "Average: " << s.average << endl;
    cout << "Max: " << s.max << endl;
    cout << "Min: " << s.min << endl;
}

