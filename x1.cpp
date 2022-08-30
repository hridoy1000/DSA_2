#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

struct edge {
    int u, v, w;
};

void assignZero(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 0;
    graph[v][u] = 0;
}

void assignOriginal(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = graph[v][u] = 1;
}

void printGraph(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int MstWeight(vector<vector<int>> &graph)
{
    int n = graph.size();
    int mstWeight = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (visited[vertex])
            continue;
        visited[vertex] = true;
        mstWeight += weight;
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (graph[vertex][i] != 0)
                pq.push({graph[vertex][i], i});
        }
    }
    return mstWeight;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > graph(n, vector<int>(n, 1));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }
    for (int i = 0; i < q; i++)
    {
        int qtype;
        cin >> qtype;
        if (qtype == 1)
        {
            int u, v;
            cin >> u >> v;
            assignZero(graph, u, v);
        }
        else if (qtype == 2)
        {
            int u, v;
            cin >> u >> v;
            assignOriginal(graph, u, v);
        }
        else
        {
            cout << MstWeight(graph) << endl;
        }
    }
    return 0;
}



