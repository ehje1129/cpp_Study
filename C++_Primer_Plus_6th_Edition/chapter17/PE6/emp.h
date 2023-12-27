#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp {
    public:
        enum classkind {Employee=1, Manager=2, Fink=3, Highfink=4};
    private:   
        std::string fname; // abstr_emp's first name
        std::string lname; // abstr_emp's last name
        std::string job;
    public:
        abstr_emp();
        abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
        virtual void ShowAll() const; // labels and shows all data
        virtual void SetAll(); // prompts user for values
        virtual void GetAll(std::istream& in);
        virtual void WriteAll(std::ostream & out);
        friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
        // just displays first and last name
        virtual ~abstr_emp() = 0; // virtual base class
};

class employee : public abstr_emp {
    private:
        classkind ck = Employee;
    public:
        employee();
        employee(const std::string & fn, const std::string & ln, const std::string & j);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void GetAll(std::istream& in);
        virtual void WriteAll(std::ostream & out);
};

class manager: virtual public abstr_emp {
    private:
        classkind ck = Manager;
        int inchargeof; // number of abstr_emps managed
    protected:
        int InChargeOf() const { return inchargeof; } // output
        int & InChargeOf(){ return inchargeof; } // input
    public:
        manager();
        manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
        manager(const abstr_emp & e, int ico);
        manager(const manager & m);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void GetAll(std::istream& in);
        virtual void WriteAll(std::ostream & out);
};

class fink: virtual public abstr_emp {
    private:
        classkind ck = Fink;
        std::string reportsto; // to whom fink reports
    protected:
        const std::string ReportsTo() const { return reportsto; }
        std::string & ReportsTo(){ return reportsto; }
    public:
        fink();
        fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
        fink(const abstr_emp & e, const std::string & rpo);
        fink(const fink & e);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void GetAll(std::istream& in);
        virtual void WriteAll(std::ostream & out);
};

class highfink: public manager, public fink {// management fink
    private:
        classkind ck = Highfink;
    public:
        highfink();
        highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
        highfink(const abstr_emp & e, const std::string & rpo, int ico);
        highfink(const fink & f, int ico);
        highfink(const manager & m, const std::string & rpo);
        highfink(const highfink & h);
        virtual void ShowAll() const;
        virtual void SetAll();
        virtual void GetAll(std::istream& in);
        virtual void WriteAll(std::ostream & out);
};

#endif