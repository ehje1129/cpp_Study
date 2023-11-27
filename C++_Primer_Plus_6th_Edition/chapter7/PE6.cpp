#include <iostream>

using namespace std;

const int ARR_SIZE = 20;

int Fill_array(double arr[], int n);
void Show_array(double arr[], int n);
double* Reverse_array(double arr[], int n);

int main()
{
    double arr[ARR_SIZE] = {};
    int cnt;
    cout << "Enter the contents of the array: ";
    cnt = Fill_array(arr, ARR_SIZE);
    Show_array(arr, cnt);
    Reverse_array(arr, cnt);
    Show_array(arr, cnt);
    Reverse_array(arr+1, cnt-2);
    Show_array(arr, cnt);
    return 0;
}

int Fill_array(double arr[], int n){
    int cnt = 0;
    double num;
    while (cin >> num){
        if(cnt == n) return cnt;
        else arr[cnt++] = num;
    }
    return cnt;
}

void Show_array(double arr[], int n){
    cout << "The contents of the array:";
    for (int i=0; i<n; i++)
        cout << " " << arr[i];
    cout << endl;
}

double* Reverse_array(double arr[], int n){
    double temp;
    for (int i=0; i<n-1; i++,n--){
        temp = arr[i];
        arr[i] = arr[n-1];
        arr[n-1] = temp;
    }
    return arr;
}
