#pragma once
#include "Node.h"
#include <string>
#include <stdio.h>

class BSTree
{
    private:
        Node *root;
    public:
        BSTree();
        void insert(int d);
        void recursiveInsert(Node *h, int d);
        std::string gds_helper(Node *n);
        std::string get_debug_string();
        void setup();
        int search(int value);
        int searchr(int value);
        int searchr(Node *n, int value);
        void Delete(Node *n,int value);
        void Delete(int value);
};