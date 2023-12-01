
#include <cstring>
#include <iostream>

using namespace std;

class golf {
    private:
        static const int Len = 40;
        char fullname[Len];
        int handicap;

    public:
        golf();
        golf(const char * name, int hc);
        void sethandicap(int hc);
        void showgolf();
};

golf::golf(const char * name, int hc){
    strcpy(fullname, name);
    handicap=hc;
}

golf::golf(){
    char fname[Len];
    int h;
    cout << "Enter the full name: ";
    cin.get(fname, Len);
    cout << "Enter the handicap: ";
    cin >> h;
    *this = golf(fname, h);
}

void golf::sethandicap(int hc){
    handicap=hc;
}

void golf::showgolf(){
    cout << "Full name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}

int main(void){
    golf empty;
    golf ann("Ann Birdfree", 24);
    empty.showgolf();
    ann.showgolf();
    ann.sethandicap(12);
    ann.showgolf();
}