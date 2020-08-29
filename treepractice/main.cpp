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

    t->insert(11);
    t->insert(4);
    t->insert(2);
    std::cout <<  t->get_debug_string() << "\n";

    std::cout << nodeCount(t->getRoot()) << "\n";
    std::cout << treeSum(t->getRoot()) << "\n";
    std::cout << treeLeaveCount(t->getRoot()) << "\n";
    std::cout << height(t->getRoot()) << "\n";
    std::cout << sum_at_level(t->getRoot(), 1) << "\n";
}
