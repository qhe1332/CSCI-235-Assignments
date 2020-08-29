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
        Node *getRoot();
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

int nodeCount(Node *r);
int treeSum(Node *r);
int treeLeaveCount(Node *r);
int height(Node *r);
int sum_at_level(Node *r, int n);
