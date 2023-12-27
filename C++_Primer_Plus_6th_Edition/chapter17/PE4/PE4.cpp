#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[]){
    using namespace std;
    if (argc != 4){
        cout << "usage: " << argv[0] << " source1 " << " source2" << "target " << endl;
        return 0;
    }

    ifstream fin1, fin2;
    ofstream fout;

    fin1.open(argv[1]);
    if (!fin1.is_open()){
        cout << "cannot open file " << argv[1] << endl;
        return 0;
    }
    fin2.open(argv[2]);
    if (!fin1.is_open()){
        cout << "cannot open file " << argv[2] << endl;
        return 0;
    }
    fout.open(argv[3]);
    if (!fout.is_open()){
        cout << "cannot open file " << argv[3] << endl;
        return 0;
    }

    string s;
    while (!fin1.eof() || !fin2.eof()){
        if (fin1.eof()){
            getline(fin2, s);
            fout << s;
        }
        else if (fin2.eof()){
            getline(fin1, s);
            fout << s;
        }
        else {
            getline(fin1, s);
            fout << s;
            getline(fin2, s);
            fout << " " << s;
        }
        if (fin1.peek() != EOF || fin2.peek() != EOF) fout << endl;
    }
}