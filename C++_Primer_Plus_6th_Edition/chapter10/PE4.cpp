#include <iostream>

namespace SALES {
    const int QUARTERS = 4;
    class Sales {
        private:
            double sales[QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales();
            Sales(const double ar[], int n);
            void showSales();
    };
}


SALES::Sales::Sales(){
    using namespace std;
    double ar[QUARTERS];
    for (int i=0; i<QUARTERS; i++){
        cout << "Enter the sales of quarter #" << i+1 << ": ";
        cin >> ar[i];
    }
    *this = Sales(ar, QUARTERS);
}

SALES::Sales::Sales(const double ar[], int n){
    int num = n<QUARTERS ? n:QUARTERS;
    min = ar[0];
    max = ar[0];
    double sum = 0;
    for (int i=0; i<QUARTERS; i++){
        if (i<num) {
            sales[i] = ar[i];
            min = min<ar[i] ? min:ar[i];
            max = max>ar[i] ? max:ar[i];
            sum += ar[i];
        }
        else sales[i] = 0;
    }
    average = sum/num;
}


void SALES::Sales::showSales(){
    using namespace std;
    cout << "Sales:";
    for (int i=0; i<QUARTERS; i++) cout << " " << sales[i];
    cout << endl;
    cout << "Average: " << average << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

int main(void){
    using namespace SALES;

    double ar1[6] {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    double ar2[2] {1.1, 2.5};
    Sales s;
    Sales s1(ar1, 6);
    Sales s2(ar2, 2);
    s.showSales();
    s1.showSales();
    s2.showSales();
}