#include "sales.h"

int main(void){
    using namespace SALES;
    Sales s;
    double ar1[6] {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    double ar2[2] {1.1, 2.5};
    setSales(s, ar1, 6);
    showSales(s);
    setSales(s, ar2, 2);
    showSales(s);
    setSales(s);
    showSales(s);
}