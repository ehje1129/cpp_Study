#include <iostream>
#include <string>
#include "dma.h"

const int CNT = 3;
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    abcDMA * p_dmas[CNT];

    p_dmas[0] = new baseDMA;
    p_dmas[1] = new lacksDMA;
    p_dmas[2] = new hasDMA;

    for (int i = 0; i < CNT; i++) {
        p_dmas[i]->view();
        cout << endl;
    }
    for (int i = 0; i < CNT; i++) {
        delete p_dmas[i]; // free memory
    }
    cout << "Done.\n";
    return 0;
}