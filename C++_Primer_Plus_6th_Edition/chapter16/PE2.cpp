#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool check_palindrome(const std::string & s);

int main(){
    using namespace std;

    string s, rs;
    cout << "Enter the string: ";
    getline(cin, s);
    while (s != "q") {
        if (check_palindrome(s))
            cout <<"\""<< s << "\" is a palindrome" << endl;
        else
            cout << "\"" << s << "\" is not a palindrome" << endl;
        getline(cin, s);
    }
    return 0;
}

bool check_palindrome(const std::string & s){
    using namespace std;
    string ss;
    for (auto i=s.begin(); i!=s.end(); i++){
        if(isalpha(*i) || isalnum(*i)) {
            ss+=tolower(*i);
        }
    }
    string rs = ss;
    reverse(rs.begin(), rs.end());
    return rs == ss;
}