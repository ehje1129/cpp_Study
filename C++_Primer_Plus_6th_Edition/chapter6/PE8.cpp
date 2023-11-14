#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input_file;
    input_file.open("pe8_ch6.txt");
    char character;
    int cnt=0;
    while (input_file >> character)
        cnt++;

    cout << "The number of characters in text file is " << cnt << endl;
    input_file.close();
    return 0;
}