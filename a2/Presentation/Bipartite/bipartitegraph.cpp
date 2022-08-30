#include<bits/stdc++.h>
#define NO_COLOR -1
#define RED 0
#define BLUE 1

using namespace std;

bool isBipartite(vector<vector<int>>& graph, int start) {
    //int V = (int) graph.size();
    int V = graph.size();

    //initialize all the color of the vertices to no color, and visited to false
    vector<int> color(V, NO_COLOR);

    // color the start vertex as BLUE, and set it as visited
    color[start] = BLUE;

    // declare a queue, and push start vertex
    queue<int> q;
    q.push(start);

    // while the q is not empty
    while(!q.empty()) {
        // extract the vertex at the front of the queue
        int vertex = q.front();
        q.pop();

        // for all its neighbours
        for(int v : graph[vertex]) {

            // if the neighbour hasn't been visited yet,
            if(color[v] == NO_COLOR) {
                /**
                 * alternate the colors, (if its BLUE, make it RED and vice versa),
                 * set visited as true and push it to the queue
                */
                if(color[vertex] == BLUE) {
                    color[v] = RED;
                } else {
                    color[v] = BLUE;
                }
                q.push(v);
            }

            /**
             * if it's already visited,
             * check if the neighbour vertex has the same color as its predecessor/parent/initial vertex
             * if they are the same color, means the belong on the same set and STILL have an edge between them
            */
            else if (color[vertex] == color[v]) {
                return false;
            }
        }

    }

    return true;

}


int main(){

    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);

    for(int i = 0; i < E; ++i) {
        int src, dest; cin >> src >> dest;
        src--; dest--; // Node start from 0 in the ppt slide there is no 0 node that's if a user input as 1 it will make 0.
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    /**
     * BIPARTITE CONDITION: vertices will belong to two sets,
     *                      but no vertices of the same set would be connected to each other
     *
     * SOLUTION: color the graph in such a way that no two connected components (side-by-side) would have the same color
    */
    cout << endl;
    cout << (isBipartite(graph, 0) ? "Yes" : "No") << "\n";

    return 0;
}
