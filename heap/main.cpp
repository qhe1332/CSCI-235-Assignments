#include <iostream>
#include "Node.h"
#include "heapTree.h"

main()
{
    heapTree *t = new heapTree();
    t->insert(5);
    t->insert(7);
    t->insert(3);
    t->siftUp();
    t->insert(10);
    t->insert(21);
    t->insert(19);
    t->insert(6);
    t->insert(8);
    std::cout << t->printHeap() << "\n";
}
