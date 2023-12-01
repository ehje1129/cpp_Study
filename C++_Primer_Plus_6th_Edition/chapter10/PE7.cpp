#include <iostream>
#include <cstring>

class Plorg {
    private:
        char name[19];
        int CI;
    public:
        Plorg(const char * n="Plorga", int i=50);
        void setCI(int i);
        void report() const;
};

Plorg::Plorg(const char * n, int i){
    using namespace std;
    strcpy(name, n);
    CI = i;
}

void Plorg::setCI(int i){
    CI = i;
}

void Plorg::report() const {
    using namespace std;
    cout << "name: " << name << endl;
    cout << "CI: " << CI << endl;
}

int main(){
    Plorg p;
    Plorg be("Betelgeusean plorg", 97);

    p.report();
    be.report();
    p.setCI(33);
    p.report();
}