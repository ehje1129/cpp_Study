#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int FEET=12;
    const double METER=0.0254;
    const double KILOGRAM=2.2;

    double feets, inches, pounds, bmi;

    cout << "Enter your height in feet and inches" << endl;
    cout << "First, feet: ";
    cin >> feets;
    cout << "Next, inches: ";
    cin >> inches;
    cout << "Enter your weight in pounds: ";
    cin >> pounds;

    bmi = pounds/KILOGRAM / sqrt((feets*FEET+inches)*METER);
    cout << "your BMI is " << bmi << endl;
}
