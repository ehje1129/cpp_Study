#ifndef CLASSIC_H_
#define CLASSIC_H

#include "cd.h"

class Classic : public Cd{
    private:
        char work[50];
    public:
        Classic(const char * s, const char * s1, const char * s2, int n, double x);
        Classic();
        virtual void Report() const;
        Classic & operator=(const Classic & c);
};

#endif