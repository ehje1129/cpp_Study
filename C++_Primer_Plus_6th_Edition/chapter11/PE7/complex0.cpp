#include <iostream>
#include "complex0.h"

complex::complex(double r, double i) {
    real = r;
    imaginary = i;
}

complex::complex() {
    real = 0;
    imaginary = 0;
}

complex::~complex(){}

void complex::reset(double r, double i){
    real = r;
    imaginary = i;
}

complex complex::operator+(complex & c) const {
    return complex(real+c.real, imaginary+c.imaginary);
}

complex complex::operator-(complex & c) const {
    return complex(real-c.real, imaginary-c.imaginary);
}

complex complex::operator*(complex & c) const {
    double r, i;
    r = real*c.real - imaginary*c.imaginary;
    i = real*c.imaginary + imaginary*c.real;
    return complex(r, i);
}

complex complex::operator*(double d) const {
    return complex(d*real, d*imaginary);
}

complex complex::operator~() {
    return complex(real, -imaginary);
}

std::ostream & operator<<(std::ostream & os, const complex & c) {
    os << "(" << c.real << "," << c.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & c){
    double r, i;
    std::cout << "real :";
    if ((is >> r).fail()) return is;
    std::cout << "imaginary: ";
    is >> i;
    is.clear();
    while (is.get() != '\n')
        continue;
    c.reset(r, i);
    return is;
}