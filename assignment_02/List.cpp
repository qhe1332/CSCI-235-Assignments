#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
	current = nullptr;
	len=0;
}

List::~List(){

	std::cout << "In the destructor\n";
	Node *t;
	while (current != nullptr){
		t = current;
		current=current->getNext();
		delete t;
	}
}

Node List::operator[](int i)
{
	Node *t = current;
	while(t->getPrior() != nullptr) // loop to the front of the list
	{
		t = (*t).getPrior();
	}
	for(int j = 0; j < i; j++) //loop till the index of element
	{
		t = (*t).getNext();
	}
	return *t;
}

void List::pushback(std::string s)
{
	Node *t = new Node(s);     //new Node
	Node *h = current;
	Node *b = current;
	while((*h).getNext() != nullptr) //loop to the last element of the list
	{
		h = (*h).getNext();
	}
	(*t).setPrior(h); //set prior for new node
	current = h;
	(*current).setNext(t); //set Next
	current = b;
	len ++; //increase length
}

void List::remove(int i)
{
	if(i >= len) //check whether it's a valid index
	{
		std::cout << "invalid index\n";
		return;
	}

	
	if(i == 0) //if removing first element
	{
		Node *t;
		t = current;
		while(t->getPrior() != nullptr) // loop to the front of the list
		{
			t = (*t).getPrior();
		}
		Node *y = t;
		t = (*t).getNext();
		delete y;
		(*t).setPrior(nullptr);
		current = t;
	}
	else
	{
		Node *t = current;
		for(int j = 0; j < i-1; j++)//loop to one before that index
		{
			t = (*t).getNext();
		}
		Node *y = (*t).getNext();
		delete y;
		(*t).setNext((*t).getNext()->getNext());
		t = (*t).getNext();
		(*t).setPrior((*t).getPrior()->getPrior());
		current = t;
	}

	len --; //decrease length
}

void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);
  
  // insert it into the list
  if(current != nullptr)
  {
		t->setPrior(current->getPrior());
		if(current->getPrior() != nullptr)
		{
			(current->getPrior())->setNext(t);
		}
		current->setPrior(t);
  }
	t->setNext(current);
  current = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t = current;
  while(t->getPrior() != nullptr) // loop to the front of the list
	{
		t = (*t).getPrior();
	}
  std::string result="null";
  while (t != nullptr){
    result = result + "<-->"  + t->getData();
    t = t->getNext();
  }
  result = result + "<-->null";

  return result;
}

int List::length(){
  // Node *t = head;
  // int l = 0;
  // while (t!=nullptr){
  //   t=t->getNext();
  //   l++;
  // }
  // return l;
  return len;
}