#include <iostream>

int main(){
    using namespace std;
    char s;
    int cnt=0;
    while(cin.get(s)){
        if (s == '$') break;
        else cnt++;
    }
    cout << "The number of characters is " << cnt << endl;
}