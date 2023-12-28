#include <iostream>
using namespace std;

template<typename T>
long double sum_values(T x){
    return x;
}

template<typename T, typename... Args>
long double sum_values(T x, Args... args){
    return x+sum_values(args...);
}

int main() {
    int a = 3;
    double b = 1.6;
    long c = 7;
    long double d = 100.17;
    cout << sum_values(a, b, c, d, 12, 11.5, 0.32);
}