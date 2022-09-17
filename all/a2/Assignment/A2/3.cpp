#include<bits/stdc++.h>
using namespace std;
# define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int V;
    list<edgeWeightPair> *adj;
    vector<int> dist ;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightPair> [V];
        dist = vector< int > (V , INF) ;
    }
    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void Dijkstra(int src)
    {
        priority_queue< edgeWeightPair, vector <edgeWeightPair> , greater<edgeWeightPair> > pq;
        vector<int> parent(V, -1);
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
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
    }
    int getDist(int node){
        return dist[node] ;
    }
};
int main()
{
    int tc ;
    cin >> tc ;
    while(tc -- ){
        int n , m ;
        cin >> n >> m ;
        Graph g(n) ;
        for(int i = 0 ; i < m ; i ++ ){
            int x , y , c ;
            cin >> x >> y >> c ;
            x -- ; y -- ;
            g.addEdge(x , y , c) ;
        }
        g.Dijkstra(2) ;
        int q ;
        cin >> q ;
        vector<int> ot;
        while(q -- ){
            int a , k ;
            cin >> a >> k ;
            a -- ;
            //cout << g.getDist(a) << endl;
            ot.push_back(max(0 , k - 2 * g.getDist(a)));
            //cout << max(0 , k - 2 * g.getDist(a)) << '\n' ;
        }
        for(auto q = ot.begin(); q != ot.end(); q++)
            cout << *q << endl;
    }

    return 0;
}
Q3: FARIA’S PLAYTIME