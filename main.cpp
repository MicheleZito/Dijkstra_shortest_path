#include "dijkstra.h"

int main()
{
    cout << endl << "\t-=-=-=-=-= Dijkstra's Shortest Path Algorithm =-=-=-=-=-"<<endl;
	cout << "\tInsert input filename -> ";
	string line;
	cin >> line;
	fstream file(line);
	Graph p;
	p.buildGraph(file);
	string src;
	cout<<endl<< "\tInsert Start Node Name -> ";
	cin >> src;
    Dijkstra Es(p);
    Es.Dijkstra_S_P(src);
    //system("pause");  <-- For Windows OS, to wait for input when executed from .exe file instead of cmd
	return(0);
}
