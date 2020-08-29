#pragma once
#include "Node.h"
#include <string>
#include <stdio.h>

class minheap
{
    private:
        Node **root;
        int length;

    public:
        minheap();
        int getLength();
        Node *getMin(); //the top of the heap
        void insert(int d);
        void siftUp();
        void siftDown();
        int removeMin();
        std::string printMinHeap();
};

class maxheap
{
    private:
        Node **root;
        int length;

    public:
        maxheap();
        int getLength();
        Node *getMax(); //the top of the heap
        void insert(int d);
        void siftUp();
        void siftDown();
        int removeMax();
        std::string printMaxHeap();
};

class heap
{
    private:
        minheap *min;
        maxheap *max;
        int length;
        double median;

    public:
        heap();
        void insert(int d);
        double getMedian();
        std::string printHeap();
};