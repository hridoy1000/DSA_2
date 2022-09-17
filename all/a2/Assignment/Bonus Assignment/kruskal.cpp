#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

typedef pair<int,int> edgeWeightpair;

class Graph
{
    int V;
    list<edgeWeightpair> * adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightpair> [V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[u].push_back(make_pair(u,w));
    }

    void pMST()
    {
        priority_queue<edgeWeightpair,vector<edgeWeightpair>,greater<edgeWeightpair>> pq;
        int s = 0;
        vector<int> key(V, INF);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        pq.push(make_pair(0,s));
        key[s] = 0;
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(inMST[u]==true)
            {
                continue;
            }
            inMST[u] = true;
            list<edgeWeightpair>::iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if(inMST[v]==false && weight < key[v])
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v],v));
                    parent[v] = u;
                }
            }
        }
        int x = 0;
        int check = V;
        for (int i = 0; i < V; i++){
            if (i==0)
            {
                continue;
            }
            if(parent[i]== -1) {
                check++;
                continue;
            }
            cout<< parent[i] << " <---- " << key[i] << " ---> " << i << endl;
        }
    }
};

int main()
{
    int n;
    cout << "How many node?\n-->";
    cin >> n;
    Graph g(n);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.pMST();
}
