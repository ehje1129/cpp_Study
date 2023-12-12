#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(const char * s, const char * s1, const char * s2, int n, double x)
    : Cd(s1, s2, n, x){
    strcpy(work, s);
}

Classic::Classic() : Cd() {
    strcpy(work, "default");
}

void Classic::Report() const {
    using namespace std;
    cout << "Primary work: " << work << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c){
    if (this == &c) return *this;
    Cd::operator=(c);
    strcpy(work, c.work);
    return *this;
}