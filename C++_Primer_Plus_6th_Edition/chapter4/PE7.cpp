#include <iostream>
#include <string>
using namespace std;

struct pizza
{
    string company_name;
    double diameter;
    double weight;
};

int main()
{
    string company_name;
    double diameter, weight;
    cout << "Enter The name of the pizza company: ";
    getline(cin, company_name);
    cout << "Enter The diameter of the pizza: ";
    cin >> diameter;
    cout << "Enter The weight of the pizza: ";
    cin >> weight;

    pizza my_pizza {company_name, diameter, weight};
    cout << "Company name: " << my_pizza.company_name << endl;
    cout << "Diameter: " << my_pizza.diameter << endl;
    cout << "Weight: " << my_pizza.weight << endl;
    return 0;
}