#include<iostream>
using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    int *marks = new int[n];
    int *time = new int[n];
    for(int i = 0; i < n; i++){
        cin >> marks[i];
    }
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[t+1];
        for(int j = 0; j <= t; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            if(time[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], marks[i-1] + dp[i-1][j-time[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][t] << endl;
    return 0;
}
