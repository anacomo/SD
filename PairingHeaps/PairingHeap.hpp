#ifndef __PAIRINGHEAP_H__
#define __PAIRINGHEAP_H__


#include "Node.cpp"


class PairingHeap
{
//private:
public:
    Node* root;
    // static
    map<int, bool> lazyDelete;
public:
    //constructor & destructor
    PairingHeap();
    PairingHeap(int key); // for insertion
    PairingHeap(Node * root); // for deletion
    ~PairingHeap();
    //methods
    //! mandatory heapify function
    void heapify(vector<int> &v);
    void makeEmpty();
    //! mandatory insert function
    void insert(int key);
    //! mandatory delete min function
    void deleteMin();
    Node* mergePairs(Node* firstSibling);
    // ! mandatory delete val function
    void deleteVal(int val);
    void reclaimMemory(Node * node);
    // const functions
    int getMin() const;
    int getSize() const;
    // friend functions or not
    friend class Node;
    // ! mandatory merge function
    PairingHeap& mergeHeaps (PairingHeap& first, PairingHeap& second);
    Node* mergeNodes(Node* firstNode, Node* secondNode);
};





#endif // __PAIRINGHEAP_H__