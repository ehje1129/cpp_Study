#include<iostream>

using namespace std;

int main(void)
{
    long long world_pop, contury_pop;
    double p;
    cout << "Enter the world's population: ";
    cin >> world_pop;
    cout << "Enter the population of the US: ";
    cin >> contury_pop;
    p = double(contury_pop) / world_pop * 100;
    cout << "The population of the US is " << p << "\% of the world population." << endl;
};
