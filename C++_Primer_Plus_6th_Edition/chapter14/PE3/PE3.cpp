#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Queue<Worker*> lolas(SIZE);
    Worker * temp;
    // Worker * lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the employee category:\n"
        << "w: waiter s: singer "
        << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice) {
            case 'w': temp = new Waiter;
            break;
            case 's': temp = new Singer;
            break;
            case 't': temp = new SingingWaiter;
            break;
        }
        cin.get();
        temp->Set();
        lolas.enqueue(temp);
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas.dequeue(temp);
        temp->Show();
        delete temp;
    }
    // for (i = 0; i < ct; i++)
    //     delete lolas[i];
    cout << "Bye.\n";
    return 0;
}