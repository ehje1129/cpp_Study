#include "emp.h"

abstr_emp::abstr_emp(): fname(""), lname(""), job("") {}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
: fname(fn), lname(ln), job(j) {}
abstr_emp::~abstr_emp() {}
void abstr_emp::ShowAll() const {
    using namespace std;
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll() {
    using namespace std;
    cout << "Enter the first name: ";
    cin >> fname;
    cout << "Enter the last name: ";
    cin >> lname;
    cout << "Enter the job: ";
    cin >> job;
}

void abstr_emp::GetAll(std::istream& in){
    std::getline(in, fname);
    std::getline(in, lname);
    std::getline(in, job);
}

void abstr_emp::WriteAll(std::ostream & out){
    out << fname << std::endl 
    << lname << std::endl 
    << job << std::endl;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
    e.ShowAll();
    return os;
}


employee::employee() : abstr_emp() {}
employee::employee(const std::string & fn, const std::string & ln, const std::string & j)
: abstr_emp(fn, ln, j) {}
void employee::ShowAll() const {
    abstr_emp::ShowAll();
}
void employee::SetAll() {
    abstr_emp::SetAll();
}
void employee::GetAll(std::istream& in){
    abstr_emp::GetAll(in);
}
void employee::WriteAll(std::ostream & out){
    out << ck << std::endl;
    abstr_emp::WriteAll(out);
}

manager::manager() : abstr_emp(), inchargeof(0) {}
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
: abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.InChargeOf()) {}
void manager::ShowAll() const{
    using namespace std;
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}
void manager::SetAll() {
    using namespace std;
    abstr_emp::SetAll();
    cout << "Enter the number of in charge of: ";
    cin >> inchargeof;
}
void manager::GetAll(std::istream& in){
    abstr_emp::GetAll(in);
    in >> inchargeof;
}
void manager::WriteAll(std::ostream & out){
    out << ck << std::endl;
    abstr_emp::WriteAll(out);
    out << inchargeof << std::endl;
}

fink::fink(): abstr_emp(), reportsto("") {}
fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
: abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink & e) : abstr_emp(e), reportsto(e.ReportsTo()) {}
void fink::ShowAll() const{
    using namespace std;
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}
void fink::SetAll(){
    using namespace std;
    abstr_emp::SetAll();
    cout << "Enter the number of reports to: ";
    cin >> reportsto;
}
void fink::GetAll(std::istream& in){
    abstr_emp::GetAll(in);
    std::getline(in, reportsto);
}
void fink::WriteAll(std::ostream & out){
    out << ck << std::endl;
    abstr_emp::WriteAll(out);
    out << reportsto << std::endl;
}

highfink::highfink() : abstr_emp(), manager(), fink() {}
highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
: abstr_emp(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink & f, int ico)
: abstr_emp(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager & m, const std::string & rpo)
: abstr_emp(m), manager(m), fink(m, rpo) {}
highfink::highfink(const highfink & h)
: abstr_emp(h), manager(h), fink(h) {}
void highfink::ShowAll() const{
    using namespace std;
    abstr_emp::ShowAll();
    cout << "In charge of: " << InChargeOf() << endl;
    cout << "Reports to: " << ReportsTo() << endl;
}
void highfink::SetAll(){
    using namespace std;
    abstr_emp::SetAll();
    cout << "Enter the number of in charge of: ";
    cin >> InChargeOf();
    cout << "Enter the number of reports to: ";
    cin >> ReportsTo();
}
void highfink::GetAll(std::istream& in){
    abstr_emp::GetAll(in);
    in >> InChargeOf();
    std::getline(in, ReportsTo());
}
void highfink::WriteAll(std::ostream & out){
    out << ck << std::endl;
    abstr_emp::WriteAll(out);
    out << InChargeOf() << std::endl;
    out << ReportsTo() << std::endl;
}