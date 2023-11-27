#include <iostream>
#include <string>
using namespace std;

struct CandyBar{
    string name;
    double weight;
    int cal;
};

void setCandyBar(CandyBar & bar, string name="Millennum Munch", const double weight=2.85, const int cal=350);
void printCandyBar(const CandyBar & bar);

int main(void){
    CandyBar bar;

    setCandyBar(bar);
    printCandyBar(bar);
    setCandyBar(bar, "name", 3.14, 289);
    printCandyBar(bar);
}

void setCandyBar(CandyBar & bar, string name, const double weight, const int cal){
    bar.name = name;
    bar.weight = weight;
    bar.cal = cal;
}

void printCandyBar(const CandyBar & bar){
    cout << bar.name << endl;
    cout << bar.weight << endl;
    cout << bar.cal << endl;
}