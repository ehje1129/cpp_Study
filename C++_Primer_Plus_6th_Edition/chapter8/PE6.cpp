#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T maxn(const T arr[], int n);
template <>
const char * maxn(const char * const arr[], int n);

int main(void){
    int arri[6] {1, 3, 5, -49, 12, 4};
    double arrd[4] {1.9, 3.4, -1.3, 2.2};
    const char * const arrc[5] {"abcd", "efghijk", "lmnopqr", "st", "uvwxyz"};
    cout << maxn(arri, 6) << endl;
    cout << maxn(arrd, 4) << endl;
    cout << maxn(arrc, 5) << endl;
}

template <class T>
T maxn(const T arr[], int n){
    T max = arr[0];
    for(int i=1;i<n;i++){
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

template <>
const char * maxn(const char* const arr[], int n){
    int max_i=0;
    int max_len = strlen(arr[0]);
    for (int i=1; i<n; i++){
        if(max_len < strlen(arr[i])){
            max_len = strlen(arr[i]);
            max_i = i;
        }
    }
    return arr[max_i];
}