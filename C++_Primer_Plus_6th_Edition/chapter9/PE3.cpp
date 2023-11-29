#include <iostream>
#include <cstring>

struct chaff {
    char dross[20];
    int slag;
};

int main(){
    using namespace std;
    chaff * cf = new chaff[2];

    strcpy(cf[0].dross, "Moon");
    cf[0].slag=1;
    strcpy(cf[1].dross, "Star");
    cf[1].slag=2;

    for(int i=0; i<2; i++){
        cout << "#" << i+1 << " dross: " << cf[i].dross << endl;
        cout << "#" << i+1 << " slag: " << cf[i].slag << endl;
    }
    delete cf;
}