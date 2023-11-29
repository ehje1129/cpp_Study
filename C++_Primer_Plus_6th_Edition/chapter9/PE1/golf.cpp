#include "golf.h"
#include <cstring>
#include <iostream>

void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname, name);
    g.handicap=hc;
}

int setgolf(golf & g){
    using namespace std;

    cout << "Enter the full name: ";
    cin.get(g.fullname, Len);
    cout << "Enter the handicap: ";
    cin >> g.handicap;

    if (strlen(g.fullname) == 0) return 0;
    else return 1;
}

void handicap(golf & g, int hc){
    g.handicap=hc;
}

void showgolf(const golf & g){
    using namespace std;
    cout << "Full name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}