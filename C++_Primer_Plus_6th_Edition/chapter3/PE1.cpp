#include <iostream>

using namespace std;

int main()
{
    const int feet=12;
    int height;
    cout << "Enter your height in integer inches: ___\b\b\b";
    cin >> height;

    cout << "Your height is " << height / feet << " feets " << height % feet << "inches" <<endl;

    return 0;
}
