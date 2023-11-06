#include<iostream>

using namespace std;

int main(void)
{
    const double miles_in_100km = 62.14;
    const double liters_in_1gallon = 3.875;
    double eu_consumption, us_consumption;
    double miles, gallons;
    cout << "Enter an automobile gasoline consumption figure in the European style(liter per 100 kilometers): ";
    cin >> eu_consumption;
    us_consumption = 1/(eu_consumption/liters_in_1gallon/miles_in_100km);
    cout << "Your automobile gasoline consumption figure is " << us_consumption << " mpg in the U.S. style" << endl;
};