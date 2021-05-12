#pragma once

#include "node.h"

class node_router: public node
{
private:
    std::vector<node*> mv_prev, mv_next; // To store pointers to previous and next 

public:

    // Constructor
    node_router(std::string name);

    // Destrutor
    ~node_router(); // Review: should be a virtual destructor

    // APIs to add nodes to the router
    virtual void add_next(node* p) override;

    virtual void add_prev(node* p) override;

    virtual bool is_node_router() override;
};
