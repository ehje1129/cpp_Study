#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex {
    private:
        double real;
        double imaginary;
    public:
        complex();
        complex(double r, double i);
        ~complex();
        void reset(double r, double i);
        complex operator+(complex & c) const;
        complex operator-(complex & c) const;
        complex operator*(complex & c) const;
        complex operator*(double d) const;
        friend complex operator*(double d, complex & c) {return c * d;};
        complex operator~();
        friend std::ostream & operator<<(std::ostream & os, const complex & c);
        friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif