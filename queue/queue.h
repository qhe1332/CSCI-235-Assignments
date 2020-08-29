#pragma once
#include <iostream>
#include "Node.h"

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4

class queueA{
private:
    int *arr;
    int index;

public:
    queueA();
    queueA(int a);
    void enqueue(int data); //adds an item to the back of the queue
    int dequeue();  //removes and returns the item from the front of the queue
    bool is_empty(); //whether or not the queue is empty
};

class queueLL{
private:    
    Node *first;
    int length;
  
public:
    queueLL();
    queueLL(Node *a); // initialize with the head of the list
    ~queueLL();
    void enqueue(int data); //adds an item to the back of the queue
    int dequeue();  //removes and returns the item from the front of the queue
    bool is_empty(); //whether or not the queue is empty
};