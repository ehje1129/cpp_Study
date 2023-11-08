#include <iostream>

using namespace std;

const double s_i = 0.1;
const double c_i = 0.05;

int main()
{
    double daphne, cleo, seed;
    int year=0;
    daphne = cleo = seed = 100;
    while(daphne>=cleo){
        year++;
        daphne += seed*s_i;
        cleo += cleo*c_i;
        cout << "In year " << year << ", Daphne has " << daphne <<"$ and Cleo has " << cleo << "$." << endl;
    }
    cout << "When the value of Cleo's investment exceeds the value of Daphne's investment is " << year << " years.";
    return 0;
}