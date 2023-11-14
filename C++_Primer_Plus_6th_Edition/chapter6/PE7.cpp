#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string word;
    int vowels, consonants, others;
    vowels = consonants = others = 0;
    cout << "Enter words (q to quit):" << endl;
    while (cin >> word && word !="q"){
        if (isalpha(word[0])) {
            switch (word[0]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
        else {
            others++;
        }
    }
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;
    return 0;
}