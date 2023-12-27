#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
std::vector<int> Lotto(int r, int s);

int main(){
    using namespace std;
    int r, s;
    cout << "Enter r, s: ";
    cin >> r;
    cin >> s;
    vector <int> winners = Lotto(r, s);
    ostream_iterator<int, char> out_iter(cout, " ");
    copy(winners.begin(), winners.end(), out_iter);
}

std::vector<int> Lotto(int r, int s){
    using namespace std;
    vector<int> nums(r);
    for (int i=0; i<r; i++) nums[i]=i;
    random_shuffle(nums.begin(), nums.end());
    return vector<int> (nums.begin(), nums.begin()+s);
}