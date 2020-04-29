#include "heap.h"

Heap::Heap(vector<GraphNode*>& Gr)
{
    this->build_heap(Gr);
}

int Heap::get_size_heap()
{
    return this->Size;
}

void Heap::build_heap(vector<GraphNode*>& Gr)
{
    if(Gr.size() <= 0)
    {
        cerr<<"[!!] Error: It's impossible to build a Heap with size <= 0 "<<endl;
        exit(1);
    }
    int CurrPos;

    for(unsigned j = 0; j < Gr.size(); j++)
       Curr_Heap.push_back(Gr[j]);
    CurrPos = (Curr_Heap.size() - 2)/2;
    Size = Curr_Heap.size();
    while(CurrPos >= 0)
    {
        Heapify_Down(CurrPos);
        CurrPos--;
    }
}

void Heap::Decrease_Key(string x,unsigned new_key)
{
    for(unsigned k = 0; k < get_size_heap(); k++)
    {
        if(Curr_Heap[k]->get_ID().compare(x) == 0)
        {
            if(Curr_Heap[k]->get_distance() > new_key)
            {
              Curr_Heap[k]->set_distance(new_key);
              this->Heapify_Up(k);
            }
        }
    }
}

int Heap::Parent(int Index)
{
    if(Index != 0)
      return (Index - 1)/2;
    else
      return Index;
}

int Heap::Sx_Child(int Ind)
{
    unsigned childpos = (2 * Ind) + 1;
    if(childpos < get_size_heap() )
        return childpos;
}

int Heap::Dx_Child(int Ind)
{
   unsigned rightchld = 2 * (Ind + 1);
   if(rightchld < get_size_heap())
    return rightchld;
}

bool Heap::Is_empty()
{
    if(this->get_size_heap() == 0)
        return true;
    else
        return false;
}

GraphNode* Heap::Extract_minimum(void)
{
    if(this->Is_empty() == true)
    {
        cerr<<"[!!] Error: It's impossibile to extract from empty Heap."<<endl;
        exit(1);
    }
    else
    {
    	GraphNode* Temp = nullptr;
        Temp = Curr_Heap[0];
        int position = get_size_heap();
        position--;
        Curr_Heap[0] = Curr_Heap[position];
        Curr_Heap.pop_back();
        Heapify_Down(0);
        Size--;
        return Temp;
     }
}

void Heap::Heapify_Down(int Ind_Start)
{
    int Child,Right;
    GraphNode* Target = Curr_Heap[Ind_Start];
    for(; (Ind_Start * 2)+1 < get_size_heap(); Ind_Start = Child)
    {
        Child = Sx_Child(Ind_Start);
        Right = Dx_Child(Ind_Start);
        if( Child != (get_size_heap() -1) && (Curr_Heap[Right]->get_distance() < Curr_Heap[Child]->get_distance()))
            Child=Right;
        if(Curr_Heap[Child]->get_distance() < Target->get_distance())
            Curr_Heap[Ind_Start] = Curr_Heap[Child];
        else
            break;
    }
    Curr_Heap[Ind_Start] = Target;
}

void Heap::Heapify_Up(int Ind_Start)
{
    int CurrPos, ParentPos;
    GraphNode* Target;
    CurrPos = Ind_Start;
    ParentPos = Parent(CurrPos);
    Target = Curr_Heap[Ind_Start];
    while(CurrPos != 0)
    {
        if(Curr_Heap[ParentPos]->get_distance() <= Target->get_distance())
            break;
        else
        {
        Curr_Heap[CurrPos] = Curr_Heap[ParentPos];
        CurrPos = ParentPos;
        ParentPos = Parent(CurrPos);
        }
    }
    Curr_Heap[CurrPos] = Target;
    Heapify_Down(0);
}

