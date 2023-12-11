#include <iostream>
#include <list>
using namespace std;

class GraphSearch
{
private:
    int V;
    list<int> *adj;

public:
    GraphSearch(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdgeToGraph(int v, int w)
    {
        adj[v].push_back(w);
        // Adding w to v’s list, as graph is undirected
        adj[w].push_back(v);
        cout << "Edge added from " << v << " to " << w << " and vice versa" << endl;
    }
};

int main()
{
    GraphSearch g(5);
    // testing the insert function
    g.addEdgeToGraph(0, 1);
    g.addEdgeToGraph(0, 4);
    g.addEdgeToGraph(1, 2);
    g.addEdgeToGraph(1, 3);
    g.addEdgeToGraph(1, 4);

    system("pause");
    return 0;
}