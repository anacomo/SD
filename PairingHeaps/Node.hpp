#ifndef __NODE_H__
#define __NODE_H__

#include<bits/stdc++.h>
using namespace std;

class Node
{
private:
    int key;
    Node* nextSibling;
    Node* leftChild;
    //static
    static int nrNodes;
public:
    Node(int key);
    Node(int key, Node* leftChild, Node* nextSibling);
    ~Node();
    // methods
    void addChild(Node* child);
    Node* mergeNodes(Node* firstNode, Node* secondNode);
    // const functions
    bool isEmpty(Node* root) const;
    // friends that will be there for you
    friend class PairingHeap;
    friend void clearMemory(Node* node);
};

#endif // __NODE_H__