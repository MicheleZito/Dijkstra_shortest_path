#include "priority_heap.h"

Priority_queue::Priority_queue(vector<GraphNode*>& G)
{
    this->My_queue = new Heap(G);
}

void Priority_queue::Change_priority(string x, unsigned new_key)
{
    this->My_queue->Decrease_Key(x,new_key);
}

GraphNode* Priority_queue::Extract_min()
{
    return this->My_queue->Extract_minimum();
}

bool Priority_queue::Empty_queue()
{
    return this->My_queue->Is_empty();
}
