#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    char input;
    cin.get(input);
    while (input != '@'){
        if (isdigit(input))
            ;
        else if (isupper(input))
            cout << (char) tolower(input);
        else if (islower(input))
            cout << (char) toupper(input);
        else
            cout << input;
        cin.get(input);
    }
    return 0;
}