#include <iostream>

using namespace std;
double convert_lightyears_to_astronomical(double);

int main()
{
    cout << "Enter the number of light years: ";
    double light_years;
    cin >> light_years;
    double ast_units = convert_lightyears_to_astronomical(light_years);
    cout << light_years << " light years = " << ast_units << " astronomical units."<< endl;
    return 0;
}

double convert_lightyears_to_astronomical(double light_years)
{
    double ast_units = light_years*63240;
    return ast_units;
}