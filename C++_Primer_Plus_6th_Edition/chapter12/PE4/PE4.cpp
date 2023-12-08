#include <iostream>
#include <cctype> // or ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
    << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
            break;
            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "stack already empty\n";
                else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
            break;
        }
        cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";

    Stack st2(st);
    Stack st3;
    st3 = st;

    for (int i=0; i<10; i++){
        if (!st.isempty()){
            st.pop(po);
            cout << "PO #" << po << " popped from st 1\n";
        }
        if (!st2.isempty()){
            st2.pop(po);
            cout << "PO #" << po << " popped from st 2\n";
        }
        if (!st3.isempty()){
            st3.pop(po);
            cout << "PO #" << po << " popped from st 3\n";
        }
    }
    return 0;
}