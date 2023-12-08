#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "queue.h"

const int MIN_PER_HR = 60;
const int SEC_PER_MIN = 60;
const int ans = 33;

bool newcustomer(double x); // is there a new customer?

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // setting things up
    std::srand(std::time(0)); // random initializing of rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs); // line queue holds up to qs people
    Queue line2(qs);
    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = SEC_PER_MIN * MIN_PER_HR * hours; // # of cycles
    cout << "Enter the average number of customers per hour: ";
    double perhour; // average # of arrival per hour
    cin >> perhour;
    double sec_per_cust; // average time between arrivals
    sec_per_cust = SEC_PER_MIN * MIN_PER_HR / perhour;
    Item temp; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    int wait_time1 = 0; // time until autoteller is free
    int wait_time2 = 0;
    long line_wait1 = 0; // cumulative time in line
    long line_wait2 = 0;
    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(sec_per_cust)) {// have newcomer
            if (line1.queuecount() < line2.queuecount()){
                if (line1.isfull())
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle); // cycle = time of arrival
                    line1.enqueue(temp); // add newcomer to line
                }
            }
            else {
                if (line2.isfull())
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle); // cycle = time of arrival
                    line2.enqueue(temp); // add newcomer to line
                }
            }
        }

        if (wait_time1 <= 0 && !line1.isempty()) {
            line1.dequeue (temp); // attend next customer
            wait_time1 = temp.ptime() * SEC_PER_MIN; // for wait_time minutes
            line_wait1 += cycle - temp.when();
            served++;
        }
        if (wait_time2 <= 0 && !line2.isempty()) {
            line2.dequeue (temp); // attend next customer
            wait_time2 = temp.ptime() * SEC_PER_MIN; // for wait_time minutes
            line_wait2 += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;
        
        sum_line += (line1.queuecount() + line2.queuecount());
    }
    // reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
        << (double) (line_wait1+line_wait2) / served / SEC_PER_MIN << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}
