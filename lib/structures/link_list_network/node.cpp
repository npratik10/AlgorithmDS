#include "pch.h"
#include "node.h"

node::node()
{
}

node::node(std::string name)
{
    m_node_name = name;
}

node::node(std::string name, uint32_t val)
{
    m_node_name = name;
    m_data = val;
    m_next = nullptr;
    m_prev = nullptr;
}

node::~node()
{
    for (auto p : m_node_vector)
        delete p;
}

void node::print_link_list(node* root)
{
    node* temp = root;
    while (temp)
    {
        std::cout << "Val: " << temp->get_data() << std::endl;
        temp = temp->get_next_ptr();
    }
}

void node::add_next(node * p)
{
}

void node::add_prev(node * p)
{
}

bool node::is_node_router()
{
    return false;
}

std::vector<node *> node::m_node_vector;
