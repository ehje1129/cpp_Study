#include <iostream>
#include <array>

using namespace std;

const int DONATION_SIZE = 10;

int main()
{
    array<double, DONATION_SIZE> donations;
    int num = 0, large=0;
    double avg, value=0, sum=0;

    cout << "Enter donation values up to 10: ";
    while (num < DONATION_SIZE && cin >> value){
        donations[num++] = value;
        sum += value;
        cout << "Enter donation values: ";    
    }
    if (num){
        avg = sum/num;
        cout << "The average of donation values is " << avg << endl;
        for (int i=0; i<num; i++)
            if (donations[i]>avg)
                large++;
        cout << "The number of values larger than aberage is " << large << endl;
    }
    else
        cout << "No input values" << endl;
        
    return 0;
}