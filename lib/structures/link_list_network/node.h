#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

class node
{
private:
    uint32_t m_data{ 0 };
    node* m_next{nullptr};
    node* m_prev{ nullptr };
    std::string m_node_name{ "" };

public:

    // Constructor
    node();

    node(std::string name);

    node(std::string name, uint32_t val);

    // Destructor
    virtual  ~node();

    // API's for settr and gettr

    // Data member
    uint32_t get_data() { return m_data; }
    void set_data(uint32_t data) { m_data = data; } // Review: Use const here on the var

    // Next pointer
    node* get_next_ptr() { return m_next; }
    void set_next_ptr(node* ptr) { m_next = ptr; }  // Review: Use const here on the pointer and other var

    // Previous pointer
    node* get_prev_ptr() { return m_prev; }
    void set_prev_ptr(node* ptr) { m_prev = ptr; }  // Review: Use const here on the pointer and other var

    // Get string name
    std::string get_node_name() { return m_node_name; }

    // static function to print the list
    static void print_link_list(node* root);  // Review: Use const here on the pointer and other var

    virtual void add_next(node* p);

    virtual void add_prev(node* p);

    virtual bool is_node_router();

    // Static varibles

    // vector to hold the node
    static std::vector<node *> m_node_vector;
};
