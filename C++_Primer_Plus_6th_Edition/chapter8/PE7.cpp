#include <iostream>

using namespace std;

template <typename T> // template A
T SumArray(T arr[], int n);
template <typename T> // template B
T SumArray(T * arr[], int n);

struct debts{
    char name[50];
    double amount;
};

int main(){
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    cout << "The sum of Mr. E's things:\n";
    // things is an array of int
    cout << SumArray(things, 6) << endl; // uses template A
    cout << "The sum ofMr. E's debts:\n";
    // pd is an array of pointers to double
    cout << SumArray(pd, 3) << endl; // uses template B (more specialized)
    return 0;
}

template <typename T>
T SumArray(T arr[], int n){
    cout << "template A\n";
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum+=arr[i];
    return sum;
}

template <typename T>
T SumArray(T * arr[], int n){
    cout << "template B\n";
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum+=*arr[i];
    return sum;
}
