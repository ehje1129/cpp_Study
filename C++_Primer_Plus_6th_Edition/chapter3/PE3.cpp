#include<iostream>

using namespace std;

int main(void)
{
    const double m2d_factor = 60;
    const double s2d_factor = 60 * 60;
    int degrees, minutes, seconds;
    double result;

    cout << "Enter a latitude in degree, minutes, and seconds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;
    result = degrees + minutes/m2d_factor + seconds/s2d_factor;
    cout << degrees;
    cout << " degrees, ";
    cout << minutes << " minutes, ";
    cout << seconds << " seconds = ";
    cout << result << " degrees" << endl;
};
