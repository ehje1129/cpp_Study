#include <iostream>

using namespace std;

double harmonic_mean(double, double);

int main()
{
    double sum_x=0.0, sum_y=0.0, mul_x=2.0, mul_y=2.0;
    double x, y;
    cout << "Enter pairs of numbers(0 0 for quit):" << endl;
    cin >> x >> y;
    while (x!=0 || y!=0){
        cout << "The harmonic means of numbers: " << harmonic_mean(x, y) << endl;
        cin >> x >> y;
    }
    return 0;
}

double harmonic_mean(double x, double y){
    return 2.0*x*y/(x+y);
}