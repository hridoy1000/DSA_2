#include<iostream>
using namespace std;

struct edge{
    int src;
    int dest;
    int weight;
};

struct subset{
    int parent;
    int rank;
};

struct activity{
    int name;
    int start;
    int end;
};

bool myFunction (activity a, activity b){
    return a.end < b.end;
}

int activity_seletion(activity arr[], int n){

    int curr =0; int next;
    cout<<arr[curr].name << " ";
    for(next=1;next<n;next++){

        if(arr[curr].end <= arr[next].start){
            curr=next;
            cout<< arr[curr].name << " ";
        }
    }
    return 0;
}

int find(struct subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int Kruskal(struct edge edges[], int n, int m){
    int i, u, v, count = 0;
    int e = 0;
    struct subset *subsets = new subset[n];
    for(i = 0; i < n; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    sort(edges, edges+m, myFunction);
    for(i = 0; i < m; i++){
        u = find(subsets, edges[i].src);
        v = find(subsets, edges[i].dest);
        if(u != v){
            Union(subsets, u, v);
            count++;
            e++;
        }
        if(count == n-1){
            break;
        }
    }
    if(e == n-1){
        cout<<"\nThe MST is \n";
        for(i = 0; i < m; i++){
            if(find(subsets, edges[i].src) != find(subsets, edges[i].dest)){
                cout<<edges[i].src<<" "<<edges[i].dest<<" "<<edges[i].weight<<endl;
            }
        }
    }
    else{
        cout<<"\nThe graph is not connected";
    }
    return 0;
}
int main(){
    int n, m;
    cin>>n>>m;
    struct edge edges[m];
    for(int i=0; i<m; i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
    Kruskal(edges, n, m);
    return 0;
}


