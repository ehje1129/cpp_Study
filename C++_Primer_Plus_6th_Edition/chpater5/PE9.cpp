#include <iostream>
#include <string>

using namespace std;
const int word_size = 30;

int main()
{
    string word;
    int num=0;
    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> word;
    while(word != "done")
    {
        num++;
        cin >> word;
    };
    cout << "You enterd a total of " << num << " words.";
    return 0;
}