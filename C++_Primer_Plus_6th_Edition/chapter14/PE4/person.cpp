#include "person.h"
#include <iostream>

void Person::Data(){
    using namespace std;
    cout << "Name: " << first_name << " " << second_name << endl;
}

void Person::Get(){
    using namespace std;
    cout << "Enter the first name: ";
    cin >> first_name;
    cout << "Enter the second name: ";
    cin >> second_name;
}

void Person::Show(){
    using namespace std;
    cout << "Type Person" << endl;
    Data();
}

void Person::Set(){
    Get();
}

void Gunslinger::Data(){
    using namespace std;
    cout << "Draw time: " << draw_t << endl;
    cout << "Number of notches: " << notches << endl;
}

void Gunslinger::Get(){
    using namespace std;
    cout << "Enter the draw time: ";
    cin >> draw_t;
    cout << "Enter the number of notches: ";
    cin >> notches;
}

void Gunslinger::Show(){
    using namespace std;
    cout << "Type Gunslinger"<< endl;
    Person::Data();
    Data();
}

void Gunslinger::Set(){
    Person::Get();
    Get();
}

void PokerPlayer::Show(){
    using namespace std;
    cout << "Type PokerPlayer" << endl;
    Data();
    cout << "Draw card " << Draw();
}

void BadDude::Show(){
    using namespace std;
    cout << "Type BadDude"<< endl;
    PokerPlayer::Data();
    Gunslinger::Data();
}

double BadDude::Gdraw(){
    return Gunslinger::Draw();
}

int BadDude::Cdraw(){
    return PokerPlayer::Draw();
}

void BadDude::Set(){
    PokerPlayer::Get();
    Gunslinger::Get();
}