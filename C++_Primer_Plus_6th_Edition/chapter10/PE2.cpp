#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Person {
private:
    static const int LIMIT = 25;
    string lname; // Person’s last name
    char fname[LIMIT]; // Person’s first name
public:
    Person() {lname = ""; fname[0] = '\0'; } // #1
    Person(const string & ln, const char * fn = "Heyyou"); // #2
    // the following methods display lname and fname
    void Show() const; // firstname lastname format
    void FormalShow() const; // lastname, firstname format
};

Person::Person(const string & ln, const char * fn) {
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const {
    cout << fname << " " << lname << endl;
}

void Person::FormalShow() const {
    cout << lname << ", " << fname << endl;
}

int main(void){
    Person one;
    Person two("Smythecraft");
    Person Three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    Three.Show();
    Three.FormalShow();
}