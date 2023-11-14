#include <iostream>
#include <string>

using namespace std;

struct contributer {
    string name;
    double donation;
};

int main()
{
    int num, donation;
    string name;
    
    cout << "Enter the number of patrons: ";
    cin >> num;
    cin.get();
    contributer *patrons = new contributer[num];
    cout << "Enter the name and contribution of each contributor" << endl;

    for (int i=0; i<num; i++){
        cout << "Name: ";
        getline(cin, name);
        cout << "Contribution: ";
        cin >> donation;
        cin.get();
        patrons[i].name = name;
        patrons[i].donation = donation;
    }

    for (int i=0; i<num; i++){
        if (patrons[i].donation >= 10000)
            cout << "[Grand Patrons] ";
        else
            cout << "[Patrons] ";
        cout << patrons[i].name << endl;
    }
    return 0;
}