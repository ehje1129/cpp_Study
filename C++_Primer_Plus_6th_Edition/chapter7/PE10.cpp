#include <iostream>

using namespace std;

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

int main()
{
    double (*pf[4]) (double, double) ={add, sub, mul, div};
    double x, y;

    while (cin >> x >> y){
        for(int i=0; i<4; i++) cout << pf[i](x, y) << endl;
    }

    return 0;
}

double add(double x, double y){
    return x+y;
}

double sub(double x, double y){
    return x-y;
}

double mul(double x, double y){
    return x*y;
}

double div(double x, double y){
    if(y) return x/y;
    else return 0;
}