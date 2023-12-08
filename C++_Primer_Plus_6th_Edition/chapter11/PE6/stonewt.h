#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt {
    public:
        enum Mode {Stone, Pounds, fp_Pounds};
    private:
        enum {Lbs_per_stn = 14}; // pounds per stone
        int stone; // whole stones
        double pds_left; // fractional pounds
        double pounds; // entire weight in pounds
        Mode mode;
    public:
        Stonewt(double lbs, Mode m = Stone); // constructor for double pounds
        Stonewt(int stn, double lbs, Mode m = Stone); // constructor for stone, lbs
        Stonewt(); // default constructor
        ~Stonewt();
        void show_lbs() const; // show weight in pounds format
        void show_stn() const; // show weight in stone format
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s); 
        friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2); 
        friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
        friend Stonewt operator*(const Stonewt & s1, const Stonewt & s2);
        friend bool operator<(const Stonewt & s1, const Stonewt & s2); 
        friend bool operator<=(const Stonewt & s1, const Stonewt & s2);
        friend bool operator>(const Stonewt & s1, const Stonewt & s2);
        friend bool operator>=(const Stonewt & s1, const Stonewt & s2); 
        friend bool operator==(const Stonewt & s1, const Stonewt & s2);
        friend bool operator!=(const Stonewt & s1, const Stonewt & s2);
};
#endif