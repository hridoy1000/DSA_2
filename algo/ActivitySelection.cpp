// Activity Selection Problems

#include <iostream>

using namespace std;

// using function to solve the problem

void activitySelection(int n, int **activities, int **dp){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(activities[i-1][1] <= j){
                dp[i][j] = max(dp[i-1][j], activities[i-1][0] + dp[i-1][j-activities[i-1][1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

//explain the problem

// n is the number of activities
// activities is the array of activities
// dp is the array of dp
// dp[i][j] is the maximum value of activities j with i activities
// dp[i][j] = max(dp[i-1][j], activities[i-1][0] + dp[i-1][j-activities[i-1][1]])



int main(){
    int n;
    cin >> n;
    int **activities = new int*[n];
    for(int i = 0; i < n; i++){
        activities[i] = new int[2];
        cin >> activities[i][0] >> activities[i][1];
    }
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    activitySelection(n, activities, dp);
    cout << dp[n][n] << endl;
    return 0;
}


