#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct contributer {
    string name;
    double donation;
};

int main()
{
    int num, donation;
    string name;
    ifstream patron_list;
    patron_list.open("pe9_ch6.txt");

    patron_list >> num;
    patron_list.get();
    contributer *patrons = new contributer[num];

    for (int i=0; i<num; i++){
        getline(patron_list, name);
        patron_list >> donation;
        patron_list.get();
        patrons[i].name = name;
        patrons[i].donation = donation;
    }
    patron_list.close();

    for (int i=0; i<num; i++){
        if (patrons[i].donation >= 10000)
            cout << "[Grand Patrons] ";
        else
            cout << "[Patrons] ";
        cout << patrons[i].name << endl;
    }
    return 0;
}