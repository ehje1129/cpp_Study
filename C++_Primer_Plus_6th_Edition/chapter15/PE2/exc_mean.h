#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error {
    public:
        bad_hmean(const char * s = "bad arguments to hmean()") : logic_error(s) {};
};

class bad_gmean : public std::logic_error {
    public:
        bad_gmean(const char * s = "bad arguments to gmean()") : std::logic_error(s) {};
};