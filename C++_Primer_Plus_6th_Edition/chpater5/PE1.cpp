#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int ans = 0;
    cout << "Enter two integers:" << endl;
    cout << "First: ";
    cin >> a;
    cout << "Second: ";
    cin >> b;
    
    for (int i=a; i<b+1; i++)
        ans+=i;

    cout << "Sum of all integers between " << a << " and " << b << " is " << ans;
    return 0;
}