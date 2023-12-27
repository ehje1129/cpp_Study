#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    int price;
};
bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool cheaperThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rp);
void ShowReview(std::shared_ptr<Review> rp);

int main() {
    using namespace std;
    vector<shared_ptr<Review>> books;
    // vector<Review> books;
    shared_ptr<Review> temp = make_shared<Review>();
    // Review temp;
    while (FillReview(temp)){
        books.push_back(temp);
        temp = make_shared<Review>();
    }

    vector<shared_ptr<Review>> t_books(books);
    sort(t_books.begin(), t_books.end());
    vector<shared_ptr<Review>> r_books(books);
    sort(r_books.begin(), r_books.end(), worseThan);
    vector<shared_ptr<Review>> p_books(books);
    sort(p_books.begin(), p_books.end(), cheaperThan);

    std::cout << "Enter sorting type\no for orignal, t for title, r for rating, p for price\n add r to reverse order,  q to quit\n:";
    std::string s;
    while (std::cin >> s){
        if(s == "o"){
            cout << "\nPrice\tRating\tBook\n";
            for_each(books.begin(), books.end(), ShowReview);
        }
        else if (s == "t"){
            cout << "Sorted by title:\nPrice\tRating\tBook\n";
            for_each(t_books.begin(), t_books.end(), ShowReview);
        }
        else if (s == "r"){
            cout << "Sorted by rating:\nPrice\tRating\tBook\n";
            for_each(r_books.begin(), r_books.end(), ShowReview);
        }
        else if (s == "p"){
            cout << "Sorted by price:\nPrice\tRating\tBook\n";
            for_each(p_books.begin(), p_books.end(), ShowReview);
        }
        else if(s == "or"){
            cout << "\nPrice\tRating\tBook\n";
            for_each(books.rbegin(), books.rend(), ShowReview);
        }
        else if (s == "tr"){
            cout << "Sorted by title:\nPrice\tRating\tBook\n";
            for_each(t_books.rbegin(), t_books.rend(), ShowReview);
        }
        else if (s == "rr"){
            cout << "Sorted by rating:\nPrice\tRating\tBook\n";
            for_each(r_books.rbegin(), r_books.rend(), ShowReview);
        }
        else if (s == "pr"){
            cout << "Sorted by price:\nPrice\tRating\tBook\n";
            for_each(p_books.rbegin(), p_books.rend(), ShowReview);
        }
        else if (s == "q") break;
        else cout << "worng command" << endl;
        while (std::cin.get() != '\n')
           continue;
    }
    cout << "Bye.\n";
    return 0;
}

bool operator<(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2) {
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}
bool worseThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2) {
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}
bool cheaperThan(std::shared_ptr<Review> r1, std::shared_ptr<Review> r2){
    if (r1->price < r2->price)
        return true;
    else
        return false;
}
bool FillReview(std::shared_ptr<Review> rp) {
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rp->title);
    if (rp->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rp->rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rp->price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}
bool displayReview(std::shared_ptr<Review> rp) {
    std::cout << "Enter sorting type (t for title, r for rating, p for price, quit to quit)\n:";
    char s;
    std::cin >> s;
    std::getline(std::cin,rp->title);
    if (rp->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rp->rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout << "Enter book price: ";
    std::cin >> rp->price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}
void ShowReview(const std::shared_ptr<Review> rp) {
    std::cout << rp->price << "\t" << rp->rating << "\t" << rp->title << std::endl;
}