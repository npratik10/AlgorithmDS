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
          ~node() { }
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

LinkList::LinkList(int val)
{
   root = new LinkList::node(val, NULL);
}

LinkList::~LinkList()
{
   LinkList::node *tmp;
   for (tmp = root; tmp != NULL; tmp = tmp->next)
      delete tmp;
}

LinkList::node *LinkList::createNode(int val)
{
   LinkList::node *temp = NULL;
   if (root == NULL)
   {
      std::cout << "Assert: No list" << std::endl;
   }
   else
   {
      temp =  new LinkList::node(val, NULL);
   }
   return temp;
}

void LinkList::addNodeFront(int val)
{
   LinkList::node *temp = createNode(val);
   temp->next = root;
   root = temp;
}

void LinkList::printList()
{
   LinkList::node *tmp;
   for (tmp = root; tmp != NULL; tmp = tmp->next)
      std::cout << "Value :" << tmp->data << std::endl;
}


int main()
{
   cout << "main" << endl;
   LinkList list1(3);
   list1.addNodeFront(5);
   list1.addNodeFront(7);
   list1.addNodeFront(9);
   list1.printList();
   return 0;
}
