// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "node_chain.h"

int main()
{
    std::cout << "Hello World!\n"; 

    node_chain* chain1 = new node_chain("chain1", "node0", 10);
    chain1->insert_node_end("node1", 14);
    chain1->insert_node_end("node2", 8);
    chain1->insert_node_begin("node3", 20);
    chain1->insert_node("node4", 25, 2);
    chain1->insert_node_end("node5", 28);
    chain1->print_chain();

    node_chain* chain2 = new node_chain("chain2", "node0", 11);
    chain2->insert_node_end("node1", 13);
    chain2->insert_node_end("node2", 7);
    chain2->insert_node_end("node3", 25);
    chain2->insert_node_end("node4", 21);
    chain2->print_chain();

    node_chain* chain3 = new node_chain("chain3", "node0", 55);
    chain3->insert_node_end("node1", 60);
    chain3->insert_node_end("node2", 72);
    chain3->insert_node_end("node3", 80);
    chain3->insert_node_end("node4", 88);
    chain3->print_chain();

    node_router* router1 = new node_router("router1");
    router1->add_prev(chain1->get_last_node());
    router1->add_next(chain2->get_root_node());
    router1->add_next(chain2->get_root_node());

    delete chain1;
    delete chain2;
    delete chain3;
    //delete router1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
