#include <iostream>
#include <fstream>

int main(int argc, char * argv[]){
    using namespace std;
    if (argc < 3) {
        cout << "usage: " << argv[0] << " source " << " target " << endl;
        return 0; 
    }

    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    if(!fin.is_open()) {
        cout << "cannot open file " << argv[1] << endl;
        return 0;
    }
    fout.open(argv[2]);
    if(!fout.is_open()) {
        cout << "cannot open file " << argv[2] << endl;
        return 0;
    }

    char s;
    while(fin.get(s)){
        fout << s;
    }
}