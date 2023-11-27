#include <iostream>

using namespace std;

const int num_filed = 47;
const int mega_filed = 27;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    int choices = 5;
    cout << "You have one chance in ";
    cout << probability(num_filed, choices) * mega_filed;
    cout << " of winning.\n";
    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ;
    return result;
}