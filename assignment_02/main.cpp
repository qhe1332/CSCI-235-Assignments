#include <iostream>
#include "Node.h"
#include "List.h"
#include <string>

int main()
{
    List *l = new List();

    l->insert("one");
    l->insert("two");
    l->insert("three");
    l->insert("four");

    std::cout << l->length() << " items in the list.\n";
    std::cout << (*l)[3].getData() << "\n";
    std::cout << (*l)[0].getData() << "\n";
    std::cout << l->getDebugString() << "\n";

    l->pushback("five");
    l->pushback("six");
    l->insert("seven");
    l->insert("eight");

    std::cout << l->length() << " items in the list.\n";
    std::cout << l->getDebugString() << "\n";
    l->remove(0);
    std::cout << l->getDebugString() << "\n";
    l->remove(5);
    std::cout << l->getDebugString() << "\n";
    l->insert("new");
    std::cout << l->getDebugString() << "\n";
    l->remove(8);  //should return invalid index
    std::cout << l->getDebugString() << "\n";

    delete l;
    std::cout << "The end\n";
    return 0;
}