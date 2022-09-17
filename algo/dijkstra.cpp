// Dijkstra

#include <iostream>
#include <vector>   

using namespace std;

// using function to solve the problem

void dijkstra(int n, int **graph, int *dist, int *prev, int start){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[start] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        int min = INT_MAX;
        for(int j = 0; j < n; j++){
            if(!visited[j] && dist[j] < min){
                u = j;
                min = dist[j];
            }
        }
        if(u == -1){
            return;
        }
        visited[u] = true;
        for(int v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] != INT_MAX){
                if(dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }
}

// explain the problem

// n is the number of nodes
// graph is the array of graph
// dist is the array of distance
// prev is the array of previous node
// start is the start node
// visited is the array of visited node
// u is the current node
// min is the minimum distance
// v is the next node

int main(){
    int n, m;
    cin >> n >> m;
    int **graph = new int*[n];
    for(int i = 0; i < n; i++){
        graph[i] = new int[n];
        for(int j = 0; j < n; j++){
            graph[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int *dist = new int[n];
    int *prev = new int[n];
    dijkstra(n, graph, dist, prev, 0);
    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << prev[i] << " ";
    }
    cout << endl;
    return 0;
}
