#include <iostream>
#include "queue.h"

////////////////////////////////////////////////////ARRAY/////////////////////////////////////////////////////////
queueA::queueA()
{
    arr = new int [100];
    index = 0;
}
queueA::queueA(int a) //initalize with length
{
    arr = new int [a];
    index = 0;
}
void queueA::enqueue(int data) //adds an item to the back of the queue
{
    arr[index] = data;
    index ++;
}
int queueA::dequeue()  //removes and returns the item from the front of the queue
{
    int r = arr[0];
    for(int i = 0; i < index; i++)
    {
        arr[i] = arr[i+1];
    }
    index --;
    arr[index] = 0;
    return r;
}
bool queueA::is_empty() //whether or not the queue is empty
{
    if(index == 0)
    {
        return true;
    }
    return false;
}


/////////////////////////////////////////////////LINKED LIST/////////////////////////////////////////////////////
queueLL::queueLL()
{
    first = nullptr;
    length = 0;
}
queueLL::queueLL(Node *a) //initialize with first head
{
    first = a;
    length = 0;
}
queueLL::~queueLL()
{
    if (first != nullptr) 
    {
        Node *t, *t2;

        t = first;
        while (t != nullptr)
        {
            t2 = t;
            t = t->getNext();
            delete t2;
        }
    }
}
void queueLL::enqueue(int data) //adds an item to the back of the queue
{
    Node *tmp = new Node(data); 
    tmp->setNext(first);
    first = tmp;
    length ++;
}
int queueLL::dequeue()  //removes and returns the item from the front of the queue
{
    if(length == 0)
    { 
        return 0; 
    }
    Node* h = first;
    Node* k = first;
    while(k->getNext() != nullptr) 
    {
        if (h != k) 
        {
            h = h->getNext();
        }
        k = h->getNext();
    }
    int output = k->getData();
    delete k;
    h->setNext(nullptr);
    length--;
    if(length == 0) 
    { 
        first = nullptr; 
    }
    
    return output;
}
bool queueLL::is_empty() //whether or not the queue is empty
{
    if(first == nullptr)
    {
        return true;
    }
    return false;
}