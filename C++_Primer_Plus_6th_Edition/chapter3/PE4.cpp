#include<iostream>

using namespace std;

int main(void)
{
    const int sec_to_min_factor = 60;
    const int min_to_hour_factor = 60;
    const int hour_to_day_factor = 24;
    int sec, min, hour, day;
    long long seconds;

    cout << "Enter the number of seconds: ";
    cin >> seconds;
    sec = seconds%sec_to_min_factor;
    min = seconds/sec_to_min_factor % min_to_hour_factor;
    hour = seconds/sec_to_min_factor/min_to_hour_factor % hour_to_day_factor;
    day = seconds/sec_to_min_factor/min_to_hour_factor/hour_to_day_factor;
    cout << seconds << " seconds = " << day << " days, " << hour << " hours, " << min << " minutes, " << sec << " seconds." << endl;
};
