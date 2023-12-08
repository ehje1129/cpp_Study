#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode m) {
    stone = int (lbs) / Lbs_per_stn; // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = m;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode m) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
    mode = m;
}

Stonewt::Stonewt() {// default constructor, wt = 0
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {// destructor
}

// show weight in stones
void Stonewt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const {
    cout << pounds << " pounds\n";
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.mode == Stonewt::Stone)
        cout << s.stone << " stone, " << s.pds_left << " pounds";
    else if (s.mode == Stonewt::Pounds)
        cout << int(s.pounds) << " pounds";
    else if (s.mode == Stonewt::fp_Pounds)
        cout << s.pounds << " pounds";
        
    return os;
}

Stonewt operator+(const Stonewt &s1, const Stonewt &s2)
{
    double sum = s1.pounds + s2.pounds;
    return Stonewt(sum, s1.mode);
}

Stonewt operator-(const Stonewt &s1, const Stonewt &s2)
{
    double diff = s1.pounds - s2.pounds;
    return Stonewt(diff, s1.mode);
}

Stonewt operator*(const Stonewt &s1, const Stonewt &s2)
{
    double mult = s1.pounds * s2.pounds;
    return Stonewt(mult, s1.mode);
}

bool operator<(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds<s2.pounds;
}
bool operator<=(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds<=s2.pounds;
}
bool operator>(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds>s2.pounds;
}
bool operator>=(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds>=s2.pounds;
}
bool operator==(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds==s2.pounds;
}
bool operator!=(const Stonewt & s1, const Stonewt & s2){
    return s1.pounds!=s2.pounds;
}