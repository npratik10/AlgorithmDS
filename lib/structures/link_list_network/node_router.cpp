#include "pch.h"
#include "node_router.h"

node_router::node_router(std::string name):
    node(name)
{
}

node_router::~node_router()
{
}

void node_router::add_next(node * p)
{
    mv_next.push_back(p);
    p->set_prev_ptr(this);
}

void node_router::add_prev(node * p) 
{
    mv_prev.push_back(p);
    p->set_next_ptr(this);
}

bool node_router::is_node_router()
{
    return true;
}


