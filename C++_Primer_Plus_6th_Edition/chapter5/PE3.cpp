#include <iostream>

using namespace std;

int main()
{
    double input, sum=0;
    do
    {
        cout << "Enter the number" << endl;
        cin >> input;
        sum+=input;
        cout << "Sum of Entries: " << sum << endl;
    } while (input != 0);
    cout << "Terminate the program. Total sum is " << sum;
    return 0;
}