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