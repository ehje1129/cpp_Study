#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void ShowStr(const std::string &s){
    std::cout << s << std::endl;
}
class Store{
    private:
        std::ostream & fout;
    public:
        Store(std::ostream & out) : fout(out) {};
        void operator()(const std::string &s);
};
void GetStrs(std::istream & in, std::vector<std::string> &vistr);

int main() {
    using namespace std;
    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin,temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    
    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void Store::operator()(const std::string &s){
    size_t len = s.length();
    fout.write((char *)&len, sizeof(size_t));
    fout.write(s.data(), len);
}
void GetStrs(std::istream & in, std::vector<std::string> &vistr){
    size_t len;
    char ch;
    while(in.read((char *)&len, sizeof(size_t))){
        std::string s;
        for (size_t i=0;i<len;i++) {
            in.read(&ch, sizeof(char));
            s.push_back(ch);
        }
        vistr.push_back(s);
    }
}