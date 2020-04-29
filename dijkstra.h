#include "priority_heap.h"

class Dijkstra
{
    private:
        Graph grp;
        multimap<GraphNode*,GraphNode*> paths;
        void Initialize_single_source(string Source);
        void Set_path(GraphNode* x, GraphNode* y){this->paths.insert(make_pair(x,y));};
        void Update_path(GraphNode* z,GraphNode* w);
        void Show_path(GraphNode* id_v);
    public:
        Dijkstra(Graph grp1){this->grp = grp1;};
        ~Dijkstra(){};
        void Dijkstra_S_P(string source);
};

