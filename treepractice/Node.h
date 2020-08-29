#pragma once

class Node
{
    private:
        int data;
        Node *left;
        Node *right;
    public:
        Node();
        Node(int d);
        Node(int d, Node *l, Node *r);

        int getData();
        Node *getLeft();
        Node *getRight();

        void setData(int d);
        void setLeft(Node *l);
        void setRight(Node *r);

};