#include "graph_node.h"

GraphNode::GraphNode()
{
    Dist_source = std::numeric_limits<int>::max();//INT_MAX;
}

unsigned GraphNode::get_edge(GraphNode* node)
{
	multimap<GraphNode*,unsigned>::iterator iter;
	iter = adjacencies.find(node);
	if(iter != adjacencies.end())
		return iter->second;
	else
		return std::numeric_limits<int>::max();//INT_MAX;
}

