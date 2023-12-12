#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x){
    performers = new char[strlen(s1)];
    label = new char[strlen(s2)];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(){
    performers = new char[8];
    label = new char[8];
    strcpy(performers, "default");
    strcpy(label, "default");
    selections = 0;
    playtime = 0;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
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

    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers)];
    label = new char[strlen(d.label)];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}