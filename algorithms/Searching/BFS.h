#pragma once

#include "node.h"

class BFS
{
public:

	Node* start_node;

	void printBFS()
	{
		std::queue<Node*>	 bfs_queue; // DFS uses a stack or a call stack
		std::set<Node*>      seen_node; // For seen node so that they can be skipped

		bfs_queue.push(start_node); // Start with the data in the start node of the graph or tree

		while (!bfs_queue.empty())
		{
			Node* curr = bfs_queue.front();
			bfs_queue.pop();

			if (seen_node.find(curr) == seen_node.end())
			{
				seen_node.emplace(curr);
				std::cout << "Data: " << curr->data;
			}

			for (auto node : curr->next_nodes)
			{
				if (seen_node.find(node) == seen_node.end())
				{
					bfs_queue.push(node);
				}
			}
		}
	}
};