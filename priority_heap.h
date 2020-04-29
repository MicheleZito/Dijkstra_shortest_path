#include "heap.h"

class Priority_queue
{
    private:
        Heap* My_queue;
    public:
        Priority_queue(vector<GraphNode*>& G);
        ~Priority_queue(){;}
        GraphNode* Extract_min();
        void Change_priority(string x, unsigned new_key);
        bool Empty_queue();
};
