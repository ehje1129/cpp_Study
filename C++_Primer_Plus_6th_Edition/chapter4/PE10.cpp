#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<double,3> time;
    cout << "Enter your three times for the 40-yd dash" << endl;
    cout << "Frist: ";
    cin >> time[0];
    cout << "Second: ";
    cin >> time[1];
    cout << "last: ";
    cin >> time[2];
    cout << "Times for the 40-yd dash: " << time[0] << "s, " << time[1] << "s, " << time[2] << "s" << endl;
    cout << "Average of Times for the 40-yd dash: " << (time[0]+time[1]+time[2])/3 << "s" << endl;
    return 0;
}