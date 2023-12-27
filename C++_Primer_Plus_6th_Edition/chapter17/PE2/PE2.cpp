#include <iostream>
#include <fstream>

int main(int argc, char * argv[]){
    using namespace std;
    if (argc < 2) return 0;

    ofstream fout;
    fout.open(argv[1]);
    char s;
    while(cin.get(s)){
        if (s == EOF) break;
        else fout << s;
    }
    return 0;
}