#include <stdio.h>
#include <iostream>
using namespace std;

class LinkList
{
    // Node Class
    class node
    {
       private:
	  // Value
          int data;
       public:
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
	  // Get Data Attribute function
	  int getData() {return data;}
    };

    private:
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
