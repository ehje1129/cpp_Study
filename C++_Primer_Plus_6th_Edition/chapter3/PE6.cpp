#include<iostream>

using namespace std;

int main(void)
{
    double kilometers, liters;
    double liters_per_100km;
    cout << "Enter the distance you have driven in kilometers: ";
    cin >> kilometers;
    cout << "Enter the amount of gasoline you have used in liters: ";
    cin >> liters;
    liters_per_100km = liters/kilometers*100;
    cout << "Your car has gotten " << liters_per_100km << " liters of gasolin per 100 kilometers." << endl;
};
