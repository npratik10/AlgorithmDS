#pragma once

#include "node_router.h"

class node_chain
{
    /*----------------- Description -------------------------
    1) Chain-
              node_0 -> node_1 -> node_2 -> node_3 -> nullptr
   nullptr <- root  <-         <-        <-

   2) Insert Node API-
   pos_0 - insert node at start of the chain
   pos_2 - insert node between node_1 and node_2
   pos_4 or greater - insert node at the end of the chain

   3) Create New Node API-

   4) Delete the chain API-

   5) Length of the chain API-

   6) Print the chain content API-
    ----------------------- End ----------------------------*/
private:
    node* root{ nullptr };

    // Create a new node
    node* get_new_node(std::string name, uint32_t val);

    // Create a new node router
    node_router* get_new_node_router(std::string name);

    std::string m_chain_name{ "" };

public:

    // Constructor
    node_chain(std::string chain_name, std::string name, uint32_t val); // Review: Use other types of constructors

    // Destructor
    ~node_chain(); // Review: Check the destructors

    // Get root node
    node* get_root_node();

    // Get last node
    node* get_last_node();

    // To insert the node at the given position in the list
    void insert_node(std::string name, uint32_t val, uint32_t pos); // Review: Use const here on the pointer and other var

    void insert_node_end(std::string name, uint32_t val); // Review: Use const here on the pointer and other var

    void insert_node_begin(std::string name, uint32_t val); // Review: Use const here on the pointer and other var

    node_router* insert_node_router_end(std::string name);

    void insert_node_router_end(node_router* node);

    node_router* insert_node_router_begin(std::string name);

    void insert_node_router_begin(node_router* node);

    // To get the length of the chain
    uint32_t get_chain_length();

    // Delete the chain
    void delete_chain();

    // API to get and set the chain name
    std::string get_chain_name();

    void set_chain_name(std::string name);

    // Print the chain
    void print_chain();
};
