#include <iostream>
#include "Node.h"
#include "heap.h"

main()
{
    heap *t = new heap();
    t->insert(5);
    t->insert(7);
    t->insert(3);
    t->insert(10);
    t->insert(21);
    t->insert(19);
    t->insert(6);
    t->insert(8);
    std::cout << t->printHeap() << "\n";
    std::cout << "Median: " << t->getMedian() << "\n";

    t->insert(1);
    std::cout << t->printHeap() << "\n";
    std::cout << "Median: " << t->getMedian() << "\n";

    t->insert(14);
    t->insert(15);
    std::cout << t->printHeap() << "\n";
    std::cout << "Median: " << t->getMedian() << "\n";


}
