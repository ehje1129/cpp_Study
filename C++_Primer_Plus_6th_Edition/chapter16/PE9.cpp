#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

int main() {
    int size;
    cout << "Enter the test size: ";
    cin >> size;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,size);

    vector<int> vi0(size);
    for(auto x: vi0) x=dist(gen);

    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());

    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "sorting time of vector int: " << (double)(end-start)/CLOCKS_PER_SEC << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << "sorting time of list int: " << (double)(end-start)/CLOCKS_PER_SEC << endl;

    copy(vi0.begin(), vi0.end(), li.begin());
    start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << "copying li to vi, sorting vi, copying vi to li time: " << (double)(end-start)/CLOCKS_PER_SEC;
}

