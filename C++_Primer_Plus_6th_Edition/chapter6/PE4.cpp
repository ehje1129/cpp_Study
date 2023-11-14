#include <iostream>

using namespace std;

const int strsize = 30, listsize=5;
struct bop {
    char fullname[strsize]; // real name
    char title[strsize]; // job title
    char bopname[strsize]; // secret BOP name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
    bop bop_list[listsize] {
        {"AAA", "aaa", "111", 0},
        {"BBB", "bbb", "222", 1},
        {"CCC", "ccc", "333", 2},
        {"DDD", "ddd", "444", 0},
        {"EEE", "eee", "555", 1}
    };

    char command;
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\t b. display by title" << endl;
    cout << "c. display by bopname\t d. display by preference" << endl;
    cout << "q. quit" << endl;

    
    cout << "Enter your choice: ";
    cin >> command;
    while (command != 'q'){
        switch (command)
        {
        case 'a':
            for (int i=0; i<listsize; i++){
                cout << bop_list[i].fullname << endl;
            }
            break;
        case 'b':
            for (int i=0; i<listsize; i++){
                cout << bop_list[i].title << endl;
            }
            break;
        case 'c':
            for (int i=0; i<listsize; i++){
                cout << bop_list[i].bopname << endl;
            }
            break;
        case 'd':
            for (int i=0; i<listsize; i++){
                switch (bop_list[i].preference)
                {
                case 0:
                    cout << bop_list[i].fullname << endl;
                    break;
                case 1:
                    cout << bop_list[i].title << endl;
                    break;
                case 2:
                    cout << bop_list[i].bopname << endl;
                    break;
                }
            }
            break;
        }
        cout << "Next choice: ";
        cin >> command;
    }
    cout << "Bye!";
    return 0;
}