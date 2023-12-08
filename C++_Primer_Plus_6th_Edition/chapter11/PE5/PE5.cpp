#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"

int main() {
    Stonewt a = 275; // uses constructor to initialize
    Stonewt b(285.7, Stonewt::fp_Pounds); // same as Stonewt wolfe = 285.7;
    Stonewt c(21, 8, Stonewt::Pounds);
    cout << "a ";
    a.show_stn();
    cout << "b ";
    b.show_stn();
    cout << "d ";
    c.show_lbs();
    a = 276.8; // uses constructor for conversion
    b = 325; // same as taft = Stonewt(325);
    cout << "a weighed ";
    cout << a << endl;
    cout << "b weighed ";
    cout << b << endl;
    cout << "c weighed ";
    cout << c << endl;
    
    cout << "a + b = " << a+b << endl;
    cout << "b - c = " << b-c << endl;
    cout << "c * a = " << c*a << endl;
    return 0;
}
