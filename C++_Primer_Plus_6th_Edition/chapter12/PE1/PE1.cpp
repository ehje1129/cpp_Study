#include "Cow.h"

int main(void) {
    Cow a;
    Cow b("bbb", "bobby", 222.2);
    Cow c = b;

    a.ShowCow();
    b.ShowCow();
    c.ShowCow();
    c = a;
    c.ShowCow();
}