#include <iostream>
#include <string>
#include "Node.h"
#include "heapTree.h"

heapTree::heapTree()
{
    root = new Node*[100];
    *root = new Node[100];
    length = 0;
}

void heapTree::insert(int d)
{
    Node *t = new Node(d);
    root[length] = t;
    length++;
    return;
}

void heapTree::siftUp()
{
    if(length < 1)
    {
        return;
    }

    int i = length-1;
    if(i > 0)
    {
        while(root[i]->getData() < root[i-1]->getData())
        {
            Node *temp = root[i];
            root[i] = root[i-1];
            root[i-1] = temp;
            i--;
        }
    }
    return;
}

void heapTree::removeMin()
{
    if(length == 0) 
    { 
        return; 
    }

    Node *temp = root[0];
    root[0] = root[length - 1];
    root[length - 1] = temp;
    
    length --;
    return;
}

std::string heapTree::printHeap()
{
    std::string output = "";
    for(int i = 0; i < length; i++)
    {
        output = output + std::to_string(root[i]->getData()) + ", "; 
    }
    return output;
}