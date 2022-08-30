#include<bits/stdc++.h>

using namespace std;


bool hasNegativeCycle(vector<vector<pair<int, int>>>& graph, int start) {
    int V = (int) graph.size();
    vector<int> distance(V, 1e9);
    distance[start] = 0;
    for(int i = 1; i <= V-1; ++i) {
        for(int node = 0; node < V; ++node) {
            for(pair<int, int> neighbour : graph[node]) {
                int neighbourIndex = neighbour.first;
                int neighbourWeight = neighbour.second;
                distance[neighbourIndex] = min(neighbourWeight + distance[node], distance[neighbourIndex]);
            }
        }
    }

    for(int node = 0; node < V; ++node) {
        for(pair<int, int> neighbour : graph[node]) {
            int neighbourIndex = neighbour.first;
            int neighbourWeight = neighbour.second;
            if(neighbourWeight + distance[node] < distance[neighbourIndex]) {
                return true;
            }
        }
    }

    return false;
}


int main(){

    int V, E; cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V);
    for(int i = 0; i < E; ++i) {
        int src, dest, weight; cin >> src >> dest >> weight;
        graph[src].push_back(make_pair(dest, weight));
    }
    int start;
    cin >> start;

    if(hasNegativeCycle(graph, start)) {
        cout << "Graph has a negative cycle\n";
    }

    else {
        cout << "Graph does not have a negative cycle\n";
    }

    return 0;
}
