#include <iostream>
#include <stdexcept>

class bad_args : public std::logic_error {
    private:
        double a;
        double b;
    public:
        bad_args(double arg1, double arg2, const char * s = "bad arguments") : a(arg1), b(arg2), logic_error(s) {}
        double get_a() {return a;}
        double get_b() {return b;}
        virtual void mesg();
};
inline void bad_args::mesg() {
    std::cout << "args " << a << ", " << b <<" are invalid arguments\n";
}

class bad_hmean : public bad_args {
    public:
        bad_hmean(double a, double b, const char * s = "bad arguments to hmean()") : bad_args(a, b, s) {}
        void mesg();
};
inline void bad_hmean::mesg() {
    std::cout << "args " << get_a() << ", " << get_b() <<" are invalid arguments";
    std::cout << " for func hmean\n";
}

class bad_gmean : public bad_args {
    public:
        bad_gmean(double a, double b, const char * s = "bad arguments to gmean()") : bad_args(a, b, s) {}
        void mesg();
};
inline void bad_gmean::mesg() {
    std::cout << "args " << get_a() << ", " << get_b() <<" are invalid arguments";
    std::cout << " for func gmean\n";
}