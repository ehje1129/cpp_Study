#include <iostream>
#include "cpmv.h"

int main(){
    Cpmv cpmv0;
    Cpmv cpmv1("aaa", "bbb");
    Cpmv cpmv2(cpmv1);
    Cpmv cpmv12(cpmv1+cpmv2);
    Cpmv cpmv3, cpmv13;
    cpmv3 = cpmv1;
    cpmv13 = cpmv1+cpmv3;

    cpmv0.Display();
    cpmv1.Display();
    cpmv2.Display();
    cpmv12.Display();
    cpmv3.Display();
    cpmv13.Display();
}
