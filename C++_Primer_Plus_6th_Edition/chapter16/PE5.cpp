#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>

const int SIZE = 10;
template <class T>
int reduce(T ar[], int n);

int main(){
    using namespace std;
    srand(time(0));
    long ar[SIZE];
    for (int i=0; i<SIZE; i++) ar[i] = rand()%SIZE;
    ostream_iterator<int, char> out_iter(cout, " ");
    copy(ar, ar+SIZE, out_iter);
    cout << endl;
    int newN = reduce(ar, SIZE);
    copy(ar, ar+newN, out_iter);
    cout << endl << newN;
}

template <class T>
int reduce(T ar[], int n){
    using namespace std;
    sort(ar, ar+n);
    ostream_iterator<int, char> out_iter(cout, " ");
    auto k = unique(ar, ar+10);
    return k-ar;
}
