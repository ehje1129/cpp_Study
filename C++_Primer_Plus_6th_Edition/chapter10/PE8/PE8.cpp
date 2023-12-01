#include <iostream>
#include "list.h"

void print(int & i);
void add5(int & i);

int main(){
    LIST l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.visit(print);
    l.visit(add5);
    l.visit(print);
}

void print(int & i){
    using namespace std;
    cout << i << endl;
}

void add5(int & i){
    i+=5;
}