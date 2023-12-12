#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x){
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(){
    strcpy(performers, "default");
    strcpy(label, "default");
    selections = 0;
    playtime = 0;
}

void Cd::Report() const {
    using namespace std;
    cout << "Performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d){
    if (this == &d)
        return *this;

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}