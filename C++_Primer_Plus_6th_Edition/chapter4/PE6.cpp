#include <iostream>
#include <string>
using namespace std;

struct snack
{
    string name;
    double weight;
    int calory;
};

void print_candybar(snack CandyBar){
    cout << "Info of candy bar" << endl;
    cout << "Name: " << CandyBar.name << endl;
    cout << "Weight: " << CandyBar.weight << endl;
    cout << "Calory: " << CandyBar.calory << endl;
}

int main()
{
    snack CandyBar[3] {
        {"Mocha Munch1", 1.3, 250},
        {"Mocha Munch2", 2.3, 350},
        {"Mocha Munch3", 3.3, 450}
    };

    print_candybar(CandyBar[0]);
    print_candybar(CandyBar[1]);
    print_candybar(CandyBar[2]);
    return 0;
}