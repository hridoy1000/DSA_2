// bellmanFord

#include <iostream>
#include <vector>

using namespace std;

// using function to solve the problem

void bellmanFord(int n, int **edges, int **dp){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(edges[i-1][0] <= j){
                dp[i][j] = max(dp[i-1][j], edges[i-1][1] + dp[i-1][j-edges[i-1][0]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

//explain the problem

// n is the number of edges
// edges is the array of edges
// dp is the array of dp
// dp[i][j] is the maximum value of edges j with i edges
// dp[i][j] = max(dp[i-1][j], edges[i-1][1] + dp[i-1][j-edges[i-1][0]])

int main(){
    int n;
    cin >> n;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[2];
        cin >> edges[i][0] >> edges[i][1];
    }
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    bellmanFord(n, edges, dp);
    cout << dp[n][n] << endl;
    return 0;
}
