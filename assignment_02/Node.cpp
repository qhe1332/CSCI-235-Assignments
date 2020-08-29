#include <iostream>

#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
  this->data = data;
  this->next = nullptr;
  this->prior = nullptr;
}


Node::Node(std::string data, Node *next){
  this->data = data;
  this->next = next;
  this->prior = nullptr;
}

Node::Node(std::string data, Node *next, Node *prior){
  this->data = data;
  this->next = next;
  this->prior = prior;
}

void Node::setData(std::string data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

void Node::setPrior(Node *prior)
{
  this->prior = prior;
}

std::string Node::getData(){
  return data;
}

Node* Node::getNext(){
  return next;
}

Node* Node::getPrior()
{
  return prior;
}