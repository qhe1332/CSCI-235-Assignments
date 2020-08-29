#pragma once
#include "Node.h"
#include <string>
#include <stdio.h>

class heapTree
{
    private:
        Node **root;
        int length;

    public:
        heapTree();
        void insert(int d);
        void siftUp();
        void removeMin();
        std::string printHeap();
};