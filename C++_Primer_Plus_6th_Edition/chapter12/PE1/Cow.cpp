#include "Cow.h"
#include <cstring>
#include <iostream>

Cow::Cow() {
    using namespace std;
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
    cout << "Default Con" << endl;
}

Cow::Cow(const char * nm, const char * ho, double wt){
    using namespace std;
    strcpy(name, nm);
    int len = strlen(ho);
    hobby = new char[len];
    strcpy(hobby, ho);
    weight = wt;
    cout << "Con" << endl;
}

Cow::Cow(const Cow & c){
    using namespace std;
    strcpy(name, c.name);
    delete [] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    cout << "Copy Con" << endl;
};

Cow::~Cow(){
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
    using namespace std;
    strcpy(name, c.name);
    delete [] hobby;
    int len = strlen(c.hobby);
    hobby = new char[len];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    cout << "Assign" << endl;
    return *this;
}

void Cow::ShowCow() const{ // display all cow data
    using namespace std;
    cout << "Name: " << name << endl;
    cout << "Hobby: " << hobby << endl;
    cout << "Weight: " << weight << endl;
}