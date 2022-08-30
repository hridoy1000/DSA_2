#include<bits/stdc++.h>
using namespace std;

class disjoint_graph
{
    int n;
    int *parent;
    int *rank;

public:
    disjoint_graph(int n) /// constructor
    {
        this->n = n;
        this->parent = new int [n];
        this->rank = new int[n];
        this->makeset();
    }

    void makeset()
    {
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int a)
    {
        if(parent[a]!=a)
        {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void union_set(int a, int b)
    {
        int a_rep = this->find(a);
        int b_rep = this->find(b);

        if(a_rep==b_rep) return;
        else
        {
            //parent[a_rep] = b_rep;
            if(rank[a_rep]>rank[b_rep])
            {
                parent[b_rep] = a_rep;
                rank[a_rep]++;
            }
            else
            {
                parent[a_rep] = b_rep;
                rank[b_rep]++;
            }
        }
    }
};

class Graph{
    int V;
    vector<vector <int>> edges;
    //disjoint_graph disj_graph;

public:
    Graph(int n)
    {
        //disj_graph = disjoint_graph(n);
        V = n;
    }

    void add_edge(int src, int dest, int weight)
    {
        edges.push_back({weight, src, dest});
    }

    int kruskal()
    {
        int min_cost = 0;
        disjoint_graph disj_graph(V);

        sort(edges.begin(), edges.end());

        for(int e=0; e<edges.size(); e++)
        {
            int weight = edges[e][0];
            int src = edges[e][1];
            int dest = edges[e][2];

            if(disj_graph.find(src) != disj_graph.find(dest))
            {
                //cout << "Added the edge " << src << "<-->" << dest << " - " << weight << endl;
                disj_graph.union_set(src, dest);
                min_cost += weight;
            }
        }

        return min_cost;
    }
};

int main()
{
    Graph graph(4);
    graph.add_edge(0, 1, 12);
    graph.add_edge(0, 2, 20);
    graph.add_edge(1, 2, 15);
    graph.add_edge(0, 3, 10);
    graph.add_edge(2, 3, 6);

    int mst_cost = graph.kruskal();
    cout << "MST COST: " << mst_cost << endl;
    return 0;
}
