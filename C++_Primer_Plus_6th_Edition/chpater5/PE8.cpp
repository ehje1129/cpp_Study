#include <iostream>
#include <cstring>

using namespace std;
const int word_size = 30;

int main()
{
    char word[word_size];
    int num=0;
    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> word;
    while(strcmp("done", word))
    {
        num++;
        cin >> word;
    };
    cout << "You enterd a total of " << num << " words.";
    return 0;
}