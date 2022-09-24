#pragma once

#include "node.h"

class DFS
{
public:

	Node* start_node;

	void printDFS()
	{
		std::stack<Node*>	 dfs_stack; // DFS uses a stack or a call stack
		std::set<Node*>      seen_node; // For seen node so that they can be skipped

		dfs_stack.push(start_node); // Start with the data in the start node of the graph or tree

		while(!dfs_stack.empty())
		{
			Node* curr = dfs_stack.top();
			dfs_stack.pop();

			if (seen_node.find(curr) == seen_node.end())
			{
				seen_node.emplace(curr);
				std::cout << "Data: " << curr->data;
			}

			for (auto node: curr->next_nodes)
			{
				if (seen_node.find(node) == seen_node.end())
				{
					dfs_stack.push(node);
				}
			}
		}
	}
};
