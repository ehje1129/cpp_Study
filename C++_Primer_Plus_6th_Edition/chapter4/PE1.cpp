#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first_name, second_name;
    char grade;
    int age;
    cout << "What is your first name? ";
    getline(cin, first_name);
    cout << "What is your last name? ";
    cin >> second_name;
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name :" << second_name << ", " << first_name << endl;
    cout << "Grade: " << char(grade+1) << endl;
    cout << "Age: " << age << endl;

    return 0;
}