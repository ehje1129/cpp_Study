#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class LIST
{
    private:
        enum {MAX = 10};
        Item items[MAX];
        int top;
    public:
        LIST();
        bool isempty() const;
        bool isfull() const;
        bool add(const Item & item);
        void visit(void (*pf)(Item & item));
};
#endif