#include <iostream>

using namespace std;

void print(char * str, int n=0);

int main(void){
    char str[] = "Hello world!";

    for (int i=0; i<10; i++){
        if (i%2)
            print(str, i%2);
        else
            print(str);
        cout << endl;
    }
}

void print(char * str, int n){
    static int cnt=0;

    if (n == 0) {
        cout << str << endl;
    }
    else {
        cnt++;
        for (int i=0; i<cnt; i++)
            cout << str << endl;
    }
}