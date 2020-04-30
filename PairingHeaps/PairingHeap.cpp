#include "PairingHeap.hpp"

//! PAIRING HEAP CLASS IMPLEMENTATION
// constructor & destructor
PairingHeap::PairingHeap() :
    root(nullptr)
{
}

PairingHeap::PairingHeap(int key) 
{
    this->root = new Node(key);
}

PairingHeap::~PairingHeap()
{
    this->makeEmpty();
}
//! mandatory heapify function
void PairingHeap::heapify(vector<int> &v) 
{
    for(size_t i = 0; i <v.size(); i++)
        this->insert(v[i]);
}

void PairingHeap::makeEmpty() 
{
    reclaimMemory(this->root);
    root = nullptr;

}

// ! mandatory insert function
void PairingHeap::insert(int key) 
{
    PairingHeap* makeHeap = new PairingHeap(key);
    *this = mergeHeaps(*this, *makeHeap);
}
// ! mandatory delete min function
void PairingHeap::deleteMin() 
{
    Node* oldRoot = root;
    if(root->leftChild == nullptr)
        root = nullptr;
    else
        mergePairs(root->leftChild);
    delete oldRoot;
    
}

Node* PairingHeap::mergePairs(Node* firstSibling) 
{
    if(firstSibling == nullptr || firstSibling->nextSibling == nullptr)
        return firstSibling;
    Node *A, *B, *newNode;
    A = firstSibling;
    B = firstSibling->nextSibling;
    newNode = firstSibling->nextSibling->nextSibling;
    A->nextSibling = nullptr;
    B->nextSibling = nullptr;
    return mergeNodes(mergeNodes(A, B), mergePairs(newNode));
}

// ! mandatory delete val function
void PairingHeap::deleteVal(int val) 
{
    if(this->root->key == val)
        this->deleteMin();
    else
    {
        lazyDelete[val] = 1;
        Node::nrNodes ++;
    }
}


void PairingHeap::reclaimMemory(Node * node) 
{
    if(node != nullptr)
    {
        reclaimMemory(node->leftChild);
        reclaimMemory(node->nextSibling);
    }
    delete node;
}

int PairingHeap::getSize() const
{
    return Node::nrNodes;
}
// ! mandatory merge function
PairingHeap& PairingHeap::mergeHeaps(PairingHeap& first, PairingHeap& second) 
{
    if(first.root == nullptr)
        return second;
    if(second.root == nullptr)
        return first;
    if(first.root->key < second.root->key)
        {
            first.root->addChild(second.root);
            return first;
        }
    second.root->addChild(first.root);
    return second;
}
