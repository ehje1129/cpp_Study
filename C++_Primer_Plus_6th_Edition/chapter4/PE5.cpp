#include <iostream>
#include <string>
using namespace std;

struct snack
{
    string name;
    double weight;
    int calory;
};

int main()
{
    snack CandyBar {
        "Mocha Munch",
        2.3,
        350
    };
    cout << "Info of candy bar" << endl;
    cout << "Name: " << CandyBar.name << endl;
    cout << "Weight: " << CandyBar.weight << endl;
    cout << "Calory: " << CandyBar.calory << endl;
    return 0;
}