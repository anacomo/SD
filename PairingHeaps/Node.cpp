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

Node* Node::mergeNodes(Node* firstNode, Node* secondNode) 
{
    if(firstNode == nullptr)
        return secondNode;
    if(secondNode == nullptr)
        return firstNode;
    if(firstNode->key < secondNode->key)
    {
        firstNode->addChild(secondNode);
        return secondNode;
    }
    else 
    {
        secondNode->addChild(firstNode);
        return firstNode;
    }
    return nullptr;
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