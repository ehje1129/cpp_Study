#include "winec.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: std::string(l), years(y), PairArray(ArrayInt (yr,y), ArrayInt(bot,y)) {}

Wine::Wine(const char * l, int y)
: std::string(l), years(y), PairArray(ArrayInt (y), ArrayInt(y)) {}

void Wine::GetBottles(){
    using namespace std;
    cout << "Enter Gully Wash data for "<< years << " year(s): " << endl;
    for (int i=0; i<years; i++){
        cout << "Enter Year: ";
        cin >> PairArray::first()[i];
        cout << "Enter bottles for that year:";
        cin >> PairArray::second()[i];
    }
}

void Wine::Show(){
    using namespace std;
    cout << "Wine: " << (const string & )(*this) << endl;
    cout << "\tYear\tBottles\n";
    for (int i=0; i<years; i++){
        cout << "\t" << PairArray::first()[i] 
        << "\t" << PairArray::second()[i] << endl;
    }
}