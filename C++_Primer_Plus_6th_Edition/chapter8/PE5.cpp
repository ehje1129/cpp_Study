#include <iostream>

using namespace std;

template <class T>
T max5(const T arr[]);

int main(void){
    int arri[5] = {1, 3, 5, -49, 12};
    double arrd[5] = {1.9, 3.4, -1.3, 2.2, 199.345};

    cout << max5(arri) << endl;
    cout << max5(arrd) << endl;
}

template <class T>
T max5(const T arr[]){
    T max = arr[0];
    for(int i=1;i<5;i++){
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}