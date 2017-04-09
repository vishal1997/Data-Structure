#include<iostream>
#include<limits>
#include<list>

using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
    bool isCycleUtil(int src,bool *visited, bool *recStack);
public:
    bool isCycle();
    void addEdge(int src, int dest);
    Graph(int vertex);
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj=new list<int>[vertex];
}

void Graph::addEdge(int src , int dest) {
    adj[src].push_back(dest);
}

bool Graph::isCycle() {
    bool *visited=new bool[vertex];
    bool *recStack=new bool[vertex];
    for(int i=0;i<vertex;i++) {
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0;i<vertex;i++)
        if(isCycleUtil(i,visited,recStack))
            return true;
    return false;
}

bool Graph::isCycleUtil(int src, bool *visited, bool *recStack) {
    visited[src]=true;
    recStack[src]=true;

    list<int>:: iterator i;

    for(i=adj[src].begin();i!=adj[src].end();i++) {
        if(!visited[*i] && isCycleUtil(*i,visited,recStack))
            return true;
        else if(recStack[*i])
            return true;
    }
    recStack[src]=false;
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
