#include <iostream>
#include <string>

using namespace std;

struct car
{
    string name;
    int year;
};

int main()
{
    int num;
    cout << "How many cars you wish to catalog?: ";
    cin >> num;
    cin.get();
    car * catalog = new car[num];

    for (int i=0; i<num; i++)
    {
        cout << "Car #" << i+1 << endl;
        cout << "Please enter the make: ";
        getline(cin, catalog[i].name);
        cout << "Please enter the year made: ";
        cin >> catalog[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for (int i=0; i<num; i++)
    {
        cout << catalog[i].year << " " << catalog[i].name << endl;
    }

    return 0;
}