#include <iostream>
#include <list>
#include <queue>
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
        //  Adding w to v’s list, as graph is undirected (ie has no direction)
        adj[w].push_back(v);
        cout << "Edge added from " << v << " to " << w << " and vice versa" << endl;
    }

    // prints BFS traversal from a given source s
    void BFSearch(int s)
    {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        // Create a queue for BFS, as BFS is same as Level Order Traversal in a tree
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        q.push(s);

        cout << "Breadth First Search starting from vertex " << s << " : ";

        while (!q.empty())
        {
            // Dequeue a vertex from the queue and print it
            s = q.front();
            cout << s << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (int i : adj[s])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
        cout << endl;
    }
};

int main()
{
    cout << "In this code edges are not weighted" << endl;
    GraphSearch graph(5);
    // testing the insert function
    graph.addEdgeToGraph(0, 1);
    graph.addEdgeToGraph(0, 4);
    graph.addEdgeToGraph(1, 2);
    graph.addEdgeToGraph(1, 3);
    graph.addEdgeToGraph(1, 4);
    cout << endl
         << endl;
    graph.BFSearch(0);
    graph.BFSearch(1);
    graph.BFSearch(2);
    graph.BFSearch(3);
    graph.BFSearch(4);

    system("pause");
    return 0;
}
