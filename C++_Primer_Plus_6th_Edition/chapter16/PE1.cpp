#include <iostream>
#include <string>
#include <algorithm>

bool check_palindrome(const std::string & s);

int main(){
    using namespace std;

    string s, rs;
    cout << "Enter the string: ";
    getline(cin, s);
    if (check_palindrome(s))
        cout <<"\""<< s << "\" is a palindrome" << endl;
    else
        cout << "\"" << s << "\" is not a palindrome" << endl;
    return 0;
}

bool check_palindrome(const std::string & s){
    using namespace std;
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs == s;
}