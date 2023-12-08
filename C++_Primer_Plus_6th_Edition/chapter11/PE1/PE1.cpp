#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include "vect.h"

int main() {
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    ofstream locations;
    locations.open("locations");

    cout << "Enter target distance (q to quit): ";

    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) break;
        locations << "Target Distance:" << target << ", Step Size: " << dstep << endl;
        locations << steps << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";

        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            locations << steps << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
        }

        cout << "After " << steps << " steps, the subject "
        "has the following location:\n";
        cout << result << endl;
        locations << "After " << steps << " steps, the subject "
        "has the following location:\n";
        locations << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
        << result.magval()/steps << endl;
        locations << " or\n" << result << endl;
        locations << "Average outward distance per step = "
        << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}