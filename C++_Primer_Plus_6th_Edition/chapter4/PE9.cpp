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
    snack *CandyBar = new snack [3];
    CandyBar[0] = {"Mocha Munch1", 1.3, 150};
    CandyBar[1] = {"Mocha Munch2", 2.3, 250};
    CandyBar[2] = {"Mocha Munch3", 3.3, 350};

    print_candybar(CandyBar[0]);
    print_candybar(CandyBar[1]);
    print_candybar(CandyBar[2]);
    return 0;
}