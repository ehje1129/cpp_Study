#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a Celsius value: ";
    double c_temperature;
    cin >> c_temperature;
    cout << c_temperature << " degrees Celsius is " << c_temperature*1.8+32.0 << " degrees Fahrenheit" << endl;
    return 0;
}