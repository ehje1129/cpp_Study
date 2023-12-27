#include <iostream>
#include <fstream>
#include "emp.h"

const int MAX = 10;

int main(void) {
    using namespace std;

    int cnt=0;
    int classtype;
    ifstream fin;
    ofstream fout;
    abstr_emp * pc[MAX];
    char ch;

    fin.open("employee");
    if (fin.is_open()) {
        while ((fin >> classtype).get(ch)){
            switch (classtype) {
                case abstr_emp::Employee:
                    pc[cnt] = new employee;
                    pc[cnt++]->GetAll(fin);
                    break;
                case abstr_emp::Manager:
                    pc[cnt] = new manager;
                    pc[cnt++]->GetAll(fin);
                    break;
                case abstr_emp::Fink:
                    pc[cnt] = new fink;
                    pc[cnt++]->GetAll(fin);
                    break;
                case abstr_emp::Highfink:
                    pc[cnt] = new highfink;
                    pc[cnt++]->GetAll(fin);
                    break;
            }
        }
    }

    for (int i=0; i<cnt; i++)
        pc[i]->ShowAll();

    for (int i=cnt; i<MAX; i++){
        cout << "1:Employee, 2:Manager, 3:Fink, 4:Highfink else:quit\nselect type of new employee: ";
        if (cin >> classtype){
            switch (classtype) {
                case abstr_emp::Employee:
                    pc[i] = new employee;
                    pc[i]->SetAll();
                    break;
                case abstr_emp::Manager:
                    pc[i] = new manager;
                    pc[i]->SetAll();
                    break;
                case abstr_emp::Fink:
                    pc[i] = new fink;
                    pc[i]->SetAll();
                    break;
                case abstr_emp::Highfink:
                    pc[i] = new highfink;
                    pc[i]->SetAll();
                    break;
            }
            cnt++;
        }
        else
            break;
    }

    fout.open("employee");
    for (int i=0; i<cnt; i++) {
        pc[i]->ShowAll();
        pc[i]->WriteAll(fout);
    }
    return 0;
}