#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <vector>
#include <list>
#include <map>
#include <iterator>
#include <fstream>
#include <cstdlib>

using namespace std;

class GraphNode{
		private:
			string ID;
			unsigned Dist_source;
			multimap<GraphNode*,unsigned> adjacencies;
		public:
			GraphNode();
			void set_ID(string name){ID = name;}
			string get_ID(){return ID;}
			unsigned get_distance(){return Dist_source;}
			void set_distance(unsigned x){Dist_source = x;}
			multimap<GraphNode*,unsigned>& get_adjacencies(){return adjacencies;}
			void set_adjacencies(GraphNode* node, unsigned weight) {adjacencies.insert(make_pair(node,weight));}
			unsigned get_edge(GraphNode*);
			~GraphNode(){;}
};
