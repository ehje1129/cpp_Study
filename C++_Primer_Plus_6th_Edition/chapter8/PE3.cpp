#include <iostream>
#include <string>

using namespace std;

void to_upper_str(string & str);

int main(void){
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin, str);
    while(str != "q"){
        to_upper_str(str);
        cout << str << endl;
        cout << "Enter a string (q to quit): ";
        getline(cin, str);
    }
    cout << "Bye.";
}

void to_upper_str(string & str){
    int i=0;
    while (str[i] != '\0'){
        str[i++] = toupper(str[i]);
    }
    
}