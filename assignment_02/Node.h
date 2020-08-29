#pragma once

class Node{
	private:
		std::string data;
		Node *prior;
		Node *next;
	public:
		Node();
		Node(std::string data);
		Node(std::string,Node* next);
		Node(std::string data, Node *next, Node *prior);

		void setData(std::string data);
		void setNext(Node *next);
		void setPrior(Node *prior);
		std::string getData();
		Node *getNext();
		Node *getPrior();
    
  
};