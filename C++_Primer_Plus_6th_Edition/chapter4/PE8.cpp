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
    pizza* my_pizza = new pizza;
    cout << "Enter The diameter of the pizza: ";
    cin >> my_pizza->diameter;
    cin.get();
    cout << "Enter The name of the pizza company: ";
    getline(cin, my_pizza->company_name);
    cout << "Enter The weight of the pizza: ";
    cin >> my_pizza->weight;
    
    cout << "Company name: " << my_pizza->company_name << endl;
    cout << "Diameter: " << my_pizza->diameter << endl;
    cout << "Weight: " << my_pizza->weight << endl;
    return 0;
}