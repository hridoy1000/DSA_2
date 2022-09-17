#include<iostream>
using namespace std;

void knapsack(int wt[], int val[], int n, int W){
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
}

int main(){
    int n, W;
    cin >> n >> W;
    int wt[n], val[n];
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    knapsack(wt, val, n, W);
    return 0;
}

//explaination

// 0-1 knapsack problem is a dynamic programming problem. 
//It is a variation of the unbounded knapsack problem. 
//In this problem, we are given a set of items, each with a weight and a value, and we are also given a knapsack of a certain capacity.
//The weight of each item is the sum of the weights of the items in the set.
//We have to find the maximum value of items that can be put in the knapsack. 
//The difference between the 0-1 knapsack problem and the unbounded knapsack problem is that in the 0-1 knapsack problem, 
//we are not allowed to take more than one instance of an item. In the unbounded knapsack problem, 
//we are allowed to take as many instances of an item as we want. The 0-1 knapsack problem is a special case of the unbounded knapsack problem.
