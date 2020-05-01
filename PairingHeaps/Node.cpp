#include "Node.hpp"

//! NODE CLASS IMPLEMENTATION

// static variable for the size of the heap
int Node::nrNodes = 0;

// constructor & destructor
Node::Node(int key) : 
    key(key), nextSibling(nullptr), leftChild(nullptr)
{
}
Node::Node(int key, Node* leftChild, Node* nextSibling) :
    key(key), leftChild(leftChild), nextSibling(nextSibling)
{
}

Node::~Node()
{
}

// methods
void Node::addChild(Node* child) 
{
    if(this->leftChild == nullptr)
        this->leftChild = child;
    else
    {
        child->nextSibling = this->leftChild;
        this->leftChild = child;
    }
    
}


// const functions
bool Node::isEmpty(Node* root) const
{
    return root == nullptr;
}
// friend functions
void clearMemory(Node * node)
{
    if(node != nullptr)
    {
        clearMemory(node->nextSibling);
        clearMemory(node->leftChild);
        delete node;
    }
}