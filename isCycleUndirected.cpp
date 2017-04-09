#include<iostream>
#include<list>
#include<limits>
using namespace std;

class Graph {
    int vertex;
    list<int> *adj;
    bool isCylceUtil(int src, bool visited[], int parent);
public:
    Graph(int vertex);
    bool isCycle();
    void addEdge(int src, int dest);
};

Graph::Graph(int vertex) {
    this->vertex=vertex;
    adj=new list<int>[vertex];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool Graph::isCylceUtil(int src, bool visited[], int parent) {
    visited[src]=true;
    list<int>::iterator i;
    for(i=adj[src].begin();i!=adj[src].end();i++) {
        if(!visited[*i]){
            if(isCylceUtil(*i,visited,src))
                return true;
        }
        else if(*i!=parent)
            return true;
    }
    return false;
}

bool Graph::isCycle() {
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    for(int i=0;i<vertex;i++)
        if(!visited[i])
            if(isCylceUtil(i,visited,-1))
                return true;

    return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCycle()? cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCycle()? cout << "Graph contains cycle\n": cout << "Graph doesn't contain cycle\n";

    return 0;
}
