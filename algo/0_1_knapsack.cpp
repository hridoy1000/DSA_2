// 0-1 knapsack

#include <iostream>

using namespace std;

// using function to solve the problem

void knapsack(int n, int m, int **bags, int **dp){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(bags[i-1][1] <= j){
                dp[i][j] = max(dp[i-1][j], bags[i-1][0] + dp[i-1][j-bags[i-1][1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
// explain the problem

// n is the number of bags
// m is the maximum weight
// k is the minimum weight
// bags is the array of bags
// dp is the array of dp
// dp[i][j] is the maximum value of weight j with i bags
// dp[i][j] = max(dp[i-1][j], bags[i-1][0] + dp[i-1][j-bags[i-1][1]])

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int **bags = new int*[n];
    for(int i = 0; i < n; i++){
        bags[i] = new int[2];
        cin >> bags[i][0] >> bags[i][1];
    }
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[m+1];
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }
    knapsack(n, m, bags, dp);
    if(dp[n][m] >= k){
        cout << "YES " << dp[n][m] << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}