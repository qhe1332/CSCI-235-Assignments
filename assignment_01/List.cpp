#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
	head = nullptr;
	len=0;
}

List::~List(){

	std::cout << "In the destructor\n";
	Node *t;
	while (head != nullptr){
		t = head;
		head=head->getNext();
		delete t;
	}
}

Node List::operator[](int i)
{
	Node *t = head;
	for(int j = 0; j < i; j++) //loop till the index of element
	{
		t = (*t).getNext();
	}
	return *t;
}

void List::pushback(std::string s)
{
	Node *t = new Node(s);     //new Node
	Node *h = head;
	while((*h).getNext() != nullptr) //loop to the last element of the list
	{
		h = (*h).getNext();
	}
	(*h).setNext(t); //set Next
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
		Node *t = head;
		Node *y = t;
		t = (*t).getNext();
		delete y;
		head = t;
	}
	else
	{
		Node *t = head;
		for(int j = 0; j < i-1; j++)
		{
			t = (*t).getNext();
		}
		Node *y = (*t).getNext();
		delete y;
		(*t).setNext((*t).getNext()->getNext());
	}

	len --; //decrease length
}

void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);
  
  // insert it into the list
  t->setNext(head);
  head = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t;
  t = head;
  std::string result="";
  while (t != nullptr){
    result = result + t->getData() + "-->";
    t = t->getNext();
  }
  result = result + "null";

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