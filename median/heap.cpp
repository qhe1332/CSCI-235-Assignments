#include <iostream>
#include <string>
#include "Node.h"
#include "heap.h"

minheap::minheap()
{
    root = new Node*[100];
    *root = new Node[100];
    length = 0;
}

int minheap::getLength()
{
    return length;
}

Node *minheap::getMin() //the top of the heap
{
    return root[0];
}

void minheap::insert(int d)
{
    Node *t = new Node(d);
    root[length] = t;
    length++;
    siftUp();
    return;
}

void minheap::siftUp()
{
    if(length < 1)
    {
        return;
    }

    for(int i = length - 1; i > 0; i--)
    {
        if(root[i]->getData() < root[i-1]->getData())
        {
            Node *temp = root[i];
            root[i] = root[i-1];
            root[i-1] = temp;
        }
    }
    return;
}

void minheap::siftDown()
{
    if(length < 1)
    {
        return;
    }

    for(int i = 0; i < length-1; i++)
    {
        if(root[i]->getData() > root[i+1]->getData())
        {
            Node *temp = root[i];
            root[i] = root[i+1];
            root[i+1] = temp;
        }
    }
    return;
}

int minheap::removeMin()
{
    if(length == 0) 
    { 
        return 0; 
    }

    Node *temp = root[0];
    root[0] = root[length - 1];
    
    length --;
    siftDown();
    return temp->getData();
}

std::string minheap::printMinHeap()
{
    std::string output = "";
    for(int i = 0; i < length; i++)
    {
        output = output + std::to_string(root[i]->getData()) + ", "; 
    }
    return output;
}

maxheap::maxheap()
{
    root = new Node*[100];
    *root = new Node[100];
    length = 0;
}

int maxheap::getLength()
{
    return length;
}

Node *maxheap::getMax() //the top of the heap
{
    return root[0];
}

void maxheap::insert(int d)
{
    Node *t = new Node(d);
    root[length] = t;
    length++;
    siftUp();
    return;
}

void maxheap::siftUp()
{
    if(length < 1)
    {
        return;
    }


    for(int i = length - 1; i > 0; i--)
    {
        if(root[i]->getData() > root[i-1]->getData())
        {
            Node *temp = root[i];
            root[i] = root[i-1];
            root[i-1] = temp;
        }
    }

    return;
}

void maxheap::siftDown()
{
    if(length < 1)
    {
        return;
    }

    for(int i = 0; i < length-1; i++)
    {
        if(root[i]->getData() < root[i+1]->getData())
        {
            Node *temp = root[i];
            root[i] = root[i+1];
            root[i+1] = temp;
        }
    }
    return;
}

int maxheap::removeMax()
{
    if(length == 0) 
    { 
        return 0; 
    }

    Node *temp = root[0];
    root[0] = root[length - 1];
    
    length --;
    siftDown();
    
    return temp->getData();
}

std::string maxheap::printMaxHeap()
{
    std::string output = "";
    for(int i = 0; i < length; i++)
    {
        output = output + std::to_string(root[i]->getData()) + ", "; 
    }
    return output;
}

heap::heap()
{
    min = new minheap();
    max = new maxheap();
    length = 0;
    median = 0;
}
void heap::insert(int d)
{
    if(length == 0)
    {
        median = d;
        min->insert(d);
        length ++;
        return;
    }

    if(d < median) //if less than median, put into maxheap, else into minheap
    {
        max->insert(d);
    }
    else
    {
        min->insert(d);
    }

    if(abs(min->getLength() - max->getLength()) > 1)//checking the length of the two heaps
    {
        if(min->getLength() > max->getLength()) //move the top of the larger heap to the smaller heap
        {
            max->insert(min->removeMin());
        }
        else
        {
            min->insert(max->removeMax());
        }
    }

    if(min->getLength() == max->getLength())//calculate the median
    {
        median = double((min->getMin()->getData() + max->getMax()->getData()))/2.0;
    }
    else if(min->getLength() > max->getLength())
    {
        median = min->getMin()->getData();
    }
    else 
    {
        median = max->getMax()->getData();
    }
    
}

double heap::getMedian()
{
    return median;
}

std::string heap::printHeap()
{
    std::string output = "Min: " + min->printMinHeap() + "\nMax: " +  max->printMaxHeap();
    return output;
}