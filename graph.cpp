#include "graph.h"

void Graph::buildGraph(fstream& file)
{

	if(file.is_open() != 1)
		exit(1);
	string number;
    getline(file,number);
    this->graph_size = atoi(number.c_str());
	string node_name;
	file.get();
	for(unsigned i=0; i<graph_size;i++)
	{
		GraphNode* temp = new GraphNode();
		getline(file,node_name,'#');
		temp->set_ID(node_name);
		v.push_back(temp);
 	}

 	vector<GraphNode*> copy = v;

 	string num1;
 	getline(file,num1);
 	for(int i=0;i<graph_size;i++)
 	{
 	    string num;
 		getline(file,num);
 		int adj = atoi(num.c_str());
 		for(int j=0;j<adj;j++)
 		{
 			string name, weight_string;
 			getline(file,name,';');
 			int weight;
 			getline(file,weight_string);
 			weight = atoi(weight_string.c_str());
 			for(unsigned k=0;k<graph_size;k++)
 			{
 				if(copy.at(k)->get_ID().compare(name) == 0)
 				{
 					v.at(i)->set_adjacencies(copy.at(k),weight);
 				}
 			}
 		}
 	}
	file.close();
	this->print_graph();
}

void Graph::print_graph()
{
	cout << "\n\t-=-=-=-=-= PRINT OF THE GRAPH =-=-=-=-=-" << endl;
	for(int i=0;i<this->graph_size;i++)
	{
		cout << "\n\tNode number " << i << " -> " << v.at(i)->get_ID() << endl;
		cout << "\tAdjacencies : " << endl;
		multimap<GraphNode*,unsigned>::iterator itera;
		for(itera = v.at(i)->get_adjacencies().begin();itera != v.at(i)->get_adjacencies().end(); itera++)
		{
			cout << "\tAdjacent to ->> " << itera->first->get_ID() << " with weight -> " << itera->second << endl;
		}
	}
}

GraphNode* Graph::get_node(string idvert)
{
    for(int x = 0; x < this->graph_size; x++)
    {
        if(v.at(x)->get_ID().compare(idvert) == 0)
            return v[x];
    }
    cout<<"\n\tnode not found"<<endl;
    system("pause");
    exit(1);
}

