#include <iostream>
#include "stonewt.h"

int main() {
    using namespace std;
    Stonewt stones[6] {Stonewt(12,5), Stonewt(275), Stonewt(125.44)};
    double pounds;
    for (int i=3; i<6; i++){
        cin >> pounds;
        stones[i] = Stonewt(pounds);
    }
    Stonewt min=stones[0], max=stones[0], eleven = Stonewt(11, 0);
    int num=0;

    cout << stones[0] << " > " << stones[1] << " is " << (stones[0]>stones[1]) << endl;
    cout << stones[1] << " >= " << stones[2] << " is " << (stones[1]>=stones[2]) << endl;
    cout << stones[2] << " < " << stones[3] << " is " << (stones[2]<stones[3]) << endl;
    cout << stones[3] << " <= " << stones[4] << " is " << (stones[3]<=stones[4]) << endl;
    cout << stones[4] << " == " << stones[5] << " is " << (stones[4]==stones[5]) << endl;
    cout << stones[5] << " != " << stones[0] << " is " << (stones[5]!=stones[0]) << endl;

    for (int i=0; i<6; i++){
        if (stones[i] >= eleven) num++;

        max = max>stones[i] ? max : stones[i];
        min = min<stones[i] ? min : stones[i];
    }

    cout << max << endl;
    cout << min << endl;
    cout << num;
    return 0;
}
