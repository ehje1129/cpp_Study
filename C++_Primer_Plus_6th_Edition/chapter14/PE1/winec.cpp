#include "winec.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: brand(l), years(y), year_bottles_pair(ArrayInt (yr,y), ArrayInt(bot,y)) {}

Wine::Wine(const char * l, int y)
: brand(l), years(y), year_bottles_pair(ArrayInt (y), ArrayInt(y)) {}

void Wine::GetBottles(){
    using namespace std;
    cout << "Enter Gully Wash data for "<< years << " year(s): " << endl;
    for (int i=0; i<years; i++){
        cout << "Enter Year: ";
        cin >> year_bottles_pair.first()[i];
        cout << "Enter bottles for that year:";
        cin >> year_bottles_pair.second()[i];
    }
}

void Wine::Show(){
    using namespace std;
    cout << "Wine: " << brand << endl;
    cout << "\tYear\tBottles\n";
    for (int i=0; i<years; i++){
        cout << "\t" << year_bottles_pair.first()[i] 
        << "\t" << year_bottles_pair.second()[i] << endl;
    }
}