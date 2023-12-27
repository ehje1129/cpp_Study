#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

class FriendList {
    private:
        std::set<std::string> flist;
    public:
        FriendList() {};
        FriendList(std::set<std::string> fl) : flist(fl) {};
        void add(const std::string & s) {flist.insert(s);}
        void display() {for (auto x: flist) std::cout << x << "\n";}
        friend FriendList merge(FriendList & fl, FriendList & fl2);
};

FriendList merge(FriendList & fl1, FriendList & fl2){
    FriendList newfl;
    std::set_union(fl1.flist.begin(), fl1.flist.end(), fl2.flist.begin(), fl2.flist.end(),
                            std::insert_iterator<std::set<std::string> >(newfl.flist, newfl.flist.begin()));
    return newfl;
}

int main(){
    using namespace std;
    FriendList Matfl, Patfl, Mergefl;
    string s;
    cout << "Enter the names of Mat's friends\n:";
    getline(cin, s);
    while (s != ""){
        Matfl.add(s);
        cout << "Enter the names of Mat's friends\n:";
        getline(cin, s);
    }
    cout << "Mat's friend list:\n";
    Matfl.display();

    cout << "Enter the names of Pat's friends\n:";
    getline(cin, s);
    while (s != ""){
        Patfl.add(s);
        cout << "Enter the names of Pat's friends\n:";
        getline(cin, s);
    }
    cout << "Pat's friend list:\n";
    Patfl.display();

    Mergefl = merge(Matfl, Patfl);
    cout << "Total friend list:\n";
    Mergefl.display();
}

