#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void print_box(box ibox);
void box_volume(box *ibox);

int main()
{
    box ibox;
    cout << "Enter the name of box: ";
    cin.getline(ibox.maker, 40);
    cout << "Enter height: ";
    cin >> ibox.height;
    cout << "Enter width: ";
    cin >> ibox.width;
    cout << "Enter length: ";
    cin >> ibox.length;
    box_volume(&ibox);
    print_box(ibox);
    return 0;
}

void print_box(box ibox){
    cout << "Name of box: " << ibox.maker << endl;
    cout << "height of box: " << ibox.height << endl;
    cout << "width of box: " << ibox.width << endl;
    cout << "length of box: " << ibox.length << endl;
    cout << "volume of box: " << ibox.volume << endl;
    return;
}

void box_volume(box *ibox){
    ibox->volume = ibox->height * ibox->width * ibox->length;
    return;
}