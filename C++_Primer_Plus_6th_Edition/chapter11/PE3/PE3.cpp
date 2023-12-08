#include <iostream>
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
    unsigned long trial;
    unsigned long hi_steps = 0;
    unsigned long lo_steps = 0;
    unsigned long sum_steps = 0;
    
    cout << "Enter target distance: ";
    cin >> target;
    cout << "Enter step length: ";
    cin >> dstep;
    cout << "Enter the number of trial: ";
    cin >> trial;
    for (int i=0; i<trial; i++) {
        while (result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
        "has the following location:\n";
        cout << result << endl;
        sum_steps+=steps;
        cout << sum_steps << endl;
        if (lo_steps == 0) {
            hi_steps = steps;
            lo_steps = steps;
        }
        else {
            hi_steps = hi_steps>steps ? hi_steps : steps;
            lo_steps = lo_steps<steps ? lo_steps : steps;
        }
        steps = 0;
        result.reset(0.0, 0.0);
    }
    cout << "hi: " << hi_steps << ", lo: " << lo_steps << ", avg: " << double(sum_steps)/trial <<endl;
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}