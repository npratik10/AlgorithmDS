#include "pch.h"
#include "node_chain.h"

node_chain::node_chain(std::string chain_name, std::string root_name, uint32_t root_val)
{
    m_chain_name = chain_name;
    root = get_new_node(root_name, root_val);
}

node_chain::~node_chain()
{
    delete_chain();
}

node * node_chain::get_root_node()
{
    return root;
}

node * node_chain::get_last_node()
{
    node* temp = root; // Using a temp node

    while (temp->get_next_ptr())
        temp = temp->get_next_ptr();

    return temp;
}

node * node_chain::get_new_node(std::string name, uint32_t val)
{
    return new node(name, val);
}

node_router * node_chain::get_new_node_router(std::string name)
{
    return new node_router(name);
}

void node_chain::insert_node(std::string name, uint32_t val, uint32_t pos)
{
    if (root == nullptr)
        return;

    node * new_node = get_new_node(name, val); // Create a new node

    node* temp = root; // Using a temp node
    uint32_t location_to_insert = pos - 1; // Get position to insert the new node

    // Traverse the chain
    while ((temp->get_next_ptr() != nullptr) && (location_to_insert))
    {
        temp = temp->get_next_ptr();
        location_to_insert--;
    }

    new_node->set_next_ptr(temp->get_next_ptr());
    temp->set_next_ptr(new_node);
    new_node->set_prev_ptr(temp);
}

void node_chain::insert_node_end(std::string name, uint32_t val)
{
    node * new_node = get_new_node(name, val);
    node* temp = root; // Using a temp node
    
    while (temp->get_next_ptr())
        temp = temp->get_next_ptr();

    temp->set_next_ptr(new_node);
}

void node_chain::insert_node_begin(std::string name, uint32_t val)
{
    node * new_node = get_new_node(name, val);
    new_node->set_next_ptr(root);
    root->set_prev_ptr(new_node);
    root = new_node;
}

node_router* node_chain::insert_node_router_end(std::string name)
{
    node_router *new_node_router = get_new_node_router(name); // Review: Lets understand a few things about the heirarchy and casting

    node* temp = root; // Using a temp node

    while (temp->get_next_ptr())
        temp = temp->get_next_ptr();

    new_node_router->add_prev(temp);
    return new_node_router;
}

void node_chain::insert_node_router_end(node_router * node_router)
{
    node* temp = root; // Using a temp node

    while (temp->get_next_ptr())
        temp = temp->get_next_ptr();

    node_router->add_prev(temp);
}

node_router * node_chain::insert_node_router_begin(std::string name)
{
    node_router *new_node_router = get_new_node_router(name); // Review: Lets understand a few things about the heirarchy and casting

    node* temp = root; // Using a temp node
    new_node_router->add_next(temp);

    return new_node_router;
}

void node_chain::insert_node_router_begin(node_router * node_router)
{
    node* temp = root; // Using a temp node
    node_router->add_next(temp);
}

uint32_t node_chain::get_chain_length()
{
    uint32_t len = 0;
    node* temp = root;

    while (temp)
    {
        temp = temp->get_next_ptr();
        len++;
    }

    return len;
}

void node_chain::delete_chain()
{
    node* next = root;
    node* prev = next;

    while (next)
    {
        next = next->get_next_ptr();
        delete prev;
        prev = next;
    }

    delete prev;
}

std::string node_chain::get_chain_name()
{
    return m_chain_name;
}

void node_chain::set_chain_name(std::string name)
{
    m_chain_name = name;
}

void node_chain::print_chain()
{
    node* temp = root;
    while (temp)
    {
        std::cout << "Val: " << temp->get_data() << std::endl;
        temp = temp->get_next_ptr();
    }
}

