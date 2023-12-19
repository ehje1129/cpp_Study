#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <cstdlib>

class Person {
    private:
        std::string first_name, second_name;
    protected:
        virtual void Data();
        virtual void Get();
    public:
        Person(const char * f, const char * s)
            : first_name(f), second_name(s) {};
        Person() : first_name("first"), second_name("second"){};
        virtual void Show();
        virtual void Set();
};

class Gunslinger : virtual public Person {
    private:
        double draw_t;
        int notches;
    protected:
        void Data();
        void Get();
    public:
        Gunslinger(const char * f, const char * s, double d, int n)
            : Person(f, s), draw_t(d), notches(n) {};
        Gunslinger() : Person("first", "second"), draw_t(0), notches(0) {};
        void Show();
        void Set();
        double Draw() {return draw_t;};
};

class PokerPlayer : virtual public Person {
    public:
        // PokerPlayer(const char * f, const char * s) : Person(f, s) {};
        void Show();
        int Draw() {return rand()%52 + 1;};
};

class BadDude : public Gunslinger, public PokerPlayer {
    public:
        BadDude() : Person(), Gunslinger(), PokerPlayer() {};
        BadDude(const char * f, const char * s, double d, int n)
            : Person(f, s), Gunslinger(f, s, d, n), PokerPlayer() {};
        double Gdraw();
        int Cdraw();
        void Show();
        void Set();
};

#endif