#include "graph.h"

class Heap
{
    public:
        Heap(vector<GraphNode*>& Gr);
        ~Heap(){};
        int get_size_heap();
        GraphNode* Extract_minimum();
        void Decrease_Key(string x, unsigned new_key);
        bool Is_empty();
    private:
        unsigned Size;
        vector<GraphNode*> Curr_Heap;
        void build_heap(vector<GraphNode*>& Gr);
        void Heapify_Down(int Ind_start);
        void Heapify_Up(int Ind_start);
        int Parent(int Index);
        int Sx_Child(int Ind);
        int Dx_Child(int Ind);
};
