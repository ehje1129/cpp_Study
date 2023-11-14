#include <iostream>

using namespace std;

int main()
{
    char input;
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\tp) pianist" << endl;
    cout << "t) tree\t\tg) game" <<endl;

    while (cin >> input){
        if (input == 'c' || input == 'p' ||input == 't' ||input == 'g')
            break;
        else
            cout << "Please enter a c, p, t, or g: ";
    }

    switch (input)
    {
    case 'c':
        cout << "Tigers are carnivores" << endl;
        break;
    case 'p':
        cout << "I want to be a pianist" << endl;
        break;
    case 't':
        cout << "A maple is tree" << endl;
        break;
    case 'g':
        cout << "I love games" << endl;
        break;
    };

    return 0;
}