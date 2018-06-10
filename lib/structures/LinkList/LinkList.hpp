#include <stdio.h>
#include <iostream>
using namespace std;

class LinkList
{
    // Node Class
    class node
    {
       public:
	  // Value
          int data;
	  // Pointer
          node *next;
          //ctor
          node(int value, node *ptr) 
          { 
	      data = value; 
	      next = ptr;
          }
	  //dtor
          ~node() {}
    };

    public:
    
    // Head Node
    node *root;

    public:
    //ctor
    LinkList(int val);
    
    //dtor
    ~LinkList();

    // Functions
    node *createNode(int val);
    void addNodeFront(int val);
    void printList();
};
