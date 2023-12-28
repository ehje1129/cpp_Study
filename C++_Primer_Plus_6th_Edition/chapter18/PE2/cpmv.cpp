#include "cpmv.h"
#include <iostream>
using namespace std;

Cpmv::Cpmv(){
    cout << "Default constructor\n";
    pi = new Info;
    pi->qcode="";
    pi->zcode="";
}
Cpmv::Cpmv(std::string q, std::string z){
    cout << "Normal constructor\n";
    pi = new Info;
    pi->qcode=q;
    pi->zcode=z;
}
Cpmv::Cpmv(const Cpmv & cp){
    cout << "Copy constructor\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;

}
Cpmv::Cpmv(Cpmv && mv){
    cout << "Move constructor\n";
    pi = mv.pi;
    mv.pi = new Info;
}
Cpmv::~Cpmv(){
    cout << "Destructor\n";
    delete pi;
}
Cpmv & Cpmv::operator=(const Cpmv & cp){
    cout << "Copy assignment\n";
    if (this == &cp) return *this;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}
Cpmv & Cpmv::operator=(Cpmv && mv){
    cout << "Move assignment\n";
    if (this == &mv) return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = new Info;
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv & obj) const{
    Cpmv temp(this->pi->qcode+obj.pi->qcode, this->pi->zcode+obj.pi->zcode);
    return temp;
}
void Cpmv::Display() const{
    cout << "qcode: "<< pi->qcode << "\nzcode: " << pi->zcode << endl;
}