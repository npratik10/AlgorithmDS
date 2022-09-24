#pragma once

#include "includes.h"

class Node
{
public:
	uint32_t data{};
	std::vector<Node*> next_nodes;
};
