#include <iostream>

using namespace std;
void display_time(int, int);

int main()
{
    cout << "Enter the number of hours: ";
    int hours;
    cin >> hours;
    cout << "Enter the number of minutes: ";
    int minutes;
    cin >> minutes;
    display_time(hours, minutes);
    return 0;
}

void display_time(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes;
}