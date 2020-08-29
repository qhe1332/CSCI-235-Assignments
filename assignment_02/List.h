#pragma once

#include <string>
#include "Node.h"

class List{
	private:
		Node *current;
		int len;
	public:
		List();
		~List();
		Node operator[](int i);
		void pushback(std::string s);      
		void remove(int i);               
		void insert(std::string data);
		std::string getDebugString();
		int length();
};
