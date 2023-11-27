#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct expense {
    double expense[Seasons];
};

void fill(expense * pa);
void show(expense da);

int main()
{
    expense expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(expense * pa) {
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa).expense[i];
    }
}

void show(expense da) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << da.expense[i] << endl;
        total += da.expense[i];
    }
    cout << "Total Expenses: $" << total << endl;
}