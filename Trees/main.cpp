#include <iostream>
#include "Node.h"
#include "BSTree.h"

main()
{
    BSTree *t = new BSTree();

    t->insert(10);
    t->insert(5);
    t->insert(15);

    std::cout <<  t->get_debug_string() << "\n";

    t->insert(3);
    t->insert(20);
    t->insert(9);
    t->insert(30);
    std::cout <<  t->get_debug_string() << "\n";

    t->Delete(30);
    std::cout <<  t->get_debug_string() << "\n";

    t->Delete(15);
    std::cout <<  t->get_debug_string() << "\n";
}