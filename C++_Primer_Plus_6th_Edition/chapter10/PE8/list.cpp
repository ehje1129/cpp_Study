#include "list.h"

LIST::LIST() {
    top = 0;
}

bool LIST::isempty() const {
    return top == 0;
}

bool LIST::isfull() const {
    return top == MAX;
}

bool LIST::add(const Item & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

void LIST::visit(void (*pf)(Item & item)) {
    for (int i=0; i<top; i++){
        pf(items[i]);
    }
}
