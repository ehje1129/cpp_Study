#include <iostream>
#include "tv.h"

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup() {
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown() {
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::set_rmmode(Remote & r){
    if (state == On)
        r.rm_mode = (r.rm_mode == r.Normal) ? r.Interactive : r.Normal;
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
        << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
        << (input == TV? "TV" : "DVD") << endl;
    }
}

void Remote::show_mode(){
    using std::cout;
    using std::endl;
    cout << "Remote is " << (rm_mode == Normal? "Normal" : "Interactive") << endl;
}