#include "graph_node.h"

class Graph
{
		private:
			vector<GraphNode*> v;
			int graph_size;
		public:
			Graph(){};
			void buildGraph(fstream&);
			void print_graph();
			int get_graph_size(){return graph_size;};
			vector<GraphNode*>& get_nodes(){return this->v;};
            GraphNode* get_node(string idvert);
			~Graph(){};
};
