#include "dijkstra.h"

void Dijkstra::Initialize_single_source(string Source)
{
    GraphNode* x = this->grp.get_node(Source);
    x->set_distance(0);
    vector<GraphNode*> copy = this->grp.get_nodes();
    for(int l = 0; l < copy.size();l++)
    {
        Set_path(copy.at(l),nullptr);
    }
}

void Dijkstra::Update_path(GraphNode* z,GraphNode* w)
{
    multimap<GraphNode*,GraphNode*>::iterator it;
    it = paths.find(z);
    if(it != paths.end())
        it->second = w;
}

void Dijkstra::Show_path(GraphNode* id_ver)
{
    if(id_ver->get_distance() < std::numeric_limits<int>::max())
        cout<<endl<<"\tNode: "<<id_ver->get_ID()<<" ; Distance from source: " << id_ver->get_distance()<<endl;
    else
        cout<<endl<<"\tNode: "<<id_ver->get_ID()<<" ; Distance from source: " << "Unreachable"<<endl;
    if(id_ver->get_distance() == 0)
        cout<<"\tSource Node."<<endl;
    else
    {
        cout<<"\tPath: "<<endl<<"\t";
        multimap<GraphNode*,GraphNode*>::iterator it1;
        it1 = paths.find(id_ver);
        cout<<"\t"<<it1->first->get_ID();
        while(it1->second != nullptr)
        {
            cout<<" <- "<<it1->second->get_ID();
            it1 = paths.find(it1->second);
        }
        cout<<endl;
    }
}

void Dijkstra::Dijkstra_S_P(string source)
{
    Initialize_single_source(source);
    Priority_queue my_queue(this->grp.get_nodes());
    list<GraphNode*> Solution;
    GraphNode* temp = new GraphNode();
    while(!my_queue.Empty_queue())
    {
        temp = my_queue.Extract_min();
        Solution.push_back(temp);
        multimap<GraphNode*,unsigned>::iterator itr;
        for(itr = temp->get_adjacencies().begin();itr != temp->get_adjacencies().end(); itr++)
        {
            if(itr->first->get_distance() > (temp->get_distance() + temp->get_edge(itr->first)))
            {
                string current_id = itr->first->get_ID();
                unsigned new_dist = temp->get_distance() + temp->get_edge(itr->first);
                my_queue.Change_priority(current_id,new_dist);
                Update_path(itr->first,temp);
            }
        }
    }
    cout<<endl<<"\t-=-=-= Dijkstra's Algorithm =-=-=-"<<endl;
    for(auto X : Solution)
        Show_path(X);
}
