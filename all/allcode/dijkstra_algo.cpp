#include<iostream>
using namespace std;
#define INF 99999999

typedef pare <int, int> edgeweightpare;


class Graph{
    int n;
    list <edgeweightpare> *adj;
public:
    Graph(int n){
        this->n = n;
        adj = new list <edgeweightpare> [n];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void printNeighbours(int u){
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            cout << it->first << " " << it->second << endl;
        }
    }
    void printGraph(){
        for(int i = 0; i < n; i++){
            cout << i << " -> ";
            printNeighbours(i);
        }
    }
}


void dijkstra(int src, vector<vector<int>> &graph, vector<int> &dist)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (visited[vertex])
            continue;
        visited[vertex] = true; 
        dist[vertex] = 0;

        dist[vertex] = weight;
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (graph[vertex][i] != 0)
                pq.push({graph[vertex][i] + weight, i});
        }
    }
}
int printSelectedNeighbours(int u, vector<vector<int>> &graph, vector<int> &dist){
    int min = INF;
    int min_index = -1;
    for(int i = 0; i < graph[u].size(); i++){
        if(graph[u][i] != 0 && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

stack<int> path;
void printPath(int src, int dest, vector<int> &parent)
{
    if (src == dest)
    {
        path.push(src);
        return;
    }
    printPath(src, parent[dest], parent);
    path.push(dest);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }
    vector<int> dist(n, INF);
    dijkstra(0, graph, dist);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;

}