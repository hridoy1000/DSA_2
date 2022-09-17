
#include<iostream>
using namespace std;
# define INF 1000000

typedef pair<int, int> edgeWeightPair;

class Graph{
    int V;
    list<edgeWeightPair> *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightPair> [V];
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void Dijkstra(int src)
    {
        priority_queue< edgeWeightPair, vector <edgeWeightPair> , greater<edgeWeightPair> > pq;
        vector<int> dist(V, INF);
        vector<int> parent(V, -1);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {

                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        printf("\n");

        for(int i = 0 ; i < V ; i ++ ){
            int u = i ;
            vector< int > t ;
            while(u != -1){
                t.push_back(u) ;
                u = parent[u] ;
            }
            cout << src;
            for(int j = t.size() - 2 ; j >= 0 ; j -- ) cout << "---( " << dist[t[j]] << " )---" << t[j] << ' ' ;
            cout << endl ;
        }
    }
};


int main(){
    int n , m ;
    cin >> n >> m ;
    Graph g(n) ;
    for(int i = 0 ; i < m ; i ++ ){
        int u , v , w ;
        cin >> u >> v >> w ;
        g.addEdge(u , v , w) ;
    }
    g.Dijkstra(0) ;
    return 0 ;
}

