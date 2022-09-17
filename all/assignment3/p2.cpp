#include<iostream>
using namespace std;

void bellmanFord(int n, int e, int **edges){
    int *dist = new int[n];
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < e; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[e];
    for(int i = 0; i < e; i++){
        edges[i] = new int[3];
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    bellmanFord(n, e, edges);
    return 0;
}




 
