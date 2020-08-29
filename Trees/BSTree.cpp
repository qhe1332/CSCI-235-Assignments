#include <iostream>
#include <string>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree()
{
    root = nullptr;
}
void BSTree::insert(int d)
{
    recursiveInsert(root, d);
}
void BSTree::recursiveInsert(Node *r, int d)
{
    Node* h = new Node(d);
    if(root == nullptr)
    {
        root = h;
    }
    else{
        if(d < r->getData())
        {
            if(r->getLeft() == nullptr )
            {
                r->setLeft(h);
            }
            else{
                recursiveInsert(r->getLeft(), d);
            } 
        }
        if(d > r->getData())
        {
            if(r->getRight() == nullptr)
            {
                r->setRight(h);
            }
            else{
                recursiveInsert(r->getRight(), d);
            }
        }
    }
}
std::string BSTree::gds_helper(Node *n)
{
    if (n == nullptr)
    {
        return "";
    } 
    else{
        return std::to_string(n->getData()) + " - " + gds_helper(n->getLeft()) + gds_helper(n->getRight());
    }
}

std::string BSTree::get_debug_string()
{
    return gds_helper(root);
}

void BSTree::setup()
{
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setRight(n);
    Node *n2 = new Node(30);
    n->setRight(n2);
    n2 = new Node(25);
    n->setLeft(n2);
    n2 = new Node(5);
    root->setLeft(n2);
    n = new Node(3);
    n2->setLeft(n);
    n = new Node(7);
    n2->setLeft(n);
}



int BSTree::search(int value)
{
    Node *t = root;

    while (t != nullptr)
    {
        if (t->getData() == value)
        {
            return value;
        }
        else if (t->getData() > value)
        {
            t = t->getLeft();
        }
        else{
            t = t->getRight();
        }
    }
    throw -1;
    return 0;
}


int BSTree::searchr(Node *n, int value)
{
    if (n == nullptr)
    {
        throw -1;
    }
    if (n->getData() == value)
    {
        return value;
    }
    else if (n->getData() > value)
    {
        return this->searchr(n->getLeft(),value);
    }
    else{
        return this->searchr(n->getRight(),value);
    }

    return 0;
  
}

int BSTree::searchr(int value)
{
    int r = this->searchr(root, value);
    return r;
}

void BSTree::Delete(Node *n,int value)
{
    if (root==nullptr){
        return;
    }

    // search for the insertion point
    Node *t = root;
    Node *t2;
    while (t!=nullptr && t->getData()  != value){
        t2 = t;
        
        if (t->getData() < value)
        t = t->getRight();
        else
        t = t->getLeft();
    }

    // if t == nullptr then the value isn't
    // in the tree
    if (t==nullptr)
        return;

    // t points to the node we want to delete
    // t2 points to its parent
    
    // The node we want to delete is a leaf
    // point t2's appropriate pointer to null
    if(t->getLeft() == nullptr && t->getRight() == nullptr)
    {
        if(t2->getData() > t->getData())
        {
            t2->setLeft(nullptr);
        }
        else
        {
            t2->setRight(nullptr);
        }
        delete(t);
        return;
    }
    
    // The node we want to delete has one child
    // point t2's appropriate pointer to t's
    // child
    Node *b;
    if(t->getLeft() == nullptr)
    {
        b = t->getRight();
        if(t2->getData() > b->getData())
        {
            t2->setLeft(b);
            delete(t);
            return;
        }
        else
        {
            t2->setRight(b);
            delete(t);
            return;
        }
        
    }
    if(t->getRight() == nullptr)
    {
        b = t->getLeft();
        if(t2->getData() > b->getData())
        {
            t2->setLeft(b);
            delete(t);
            return;
        }
        else
        {
            t2->setRight(b);
            delete(t);
            return;
        }
    }

    // Note - the above two cases can be combined
    
    // the node we want to delete has two children
    // 1. Replace the node we want to delete
    //    with either the largest value in its
    //    left subtree or the smallest value in
    //    its right subtree 
    Node *c = t;
    
    
    // we find the largest on the left subtree by
    // going to left child and then as far right as
    // we can
    while(c->getLeft() != nullptr)
    {
        c = c->getLeft();
    }

    if(t2->getData() > t->getData())
    {
        t2->setLeft(c);
    }
    else
    {
        t2->setRight(c);
    }
    c->setLeft(t->getLeft());
    c->setRight(t->getRight());

    // we find the smallest on the right subtree by
    // going to the right child and then as far left
    // as we can.

    // 2. We can then delete the node that we relaced
    //   from by recursively calling delete
    // on the subtree where that node lives.
    Delete(c->getLeft(), c->getData());

    // IMPORTANT CAVEAT - if you want to delete the
    // root you might need some special case code
  
}

void BSTree::Delete(int value)
{
    Delete (root,value);
}