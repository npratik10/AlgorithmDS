#include "LinkList.hpp"

LinkList::LinkList(int val)
{
   root = new LinkList::node(val, NULL);
}

LinkList::~LinkList()
{
   //LinkList::node *tmp;
   //for (tmp = root; tmp != NULL; tmp = tmp->next)
      //delete tmp;
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
      std::cout << "Value :" << tmp->getData() << std::endl;
}
