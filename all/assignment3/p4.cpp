#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int **time = new int*[n];
    for(int i = 0; i < n; i++){
        time[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> time[i][j];
        }
    }
    int m;
    cin >> m;
    while(m--){
        int s, g, d;
        cin >> s >> g >> d;
        int **dp = new int*[n];
        for(int i = 0; i < n; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(dp[j][k] == 0){
                        dp[j][k] = time[j][i] + time[i][k];
                    }
                    else{
                        dp[j][k] = min(dp[j][k], time[j][i] + time[i][k]);
                    }
                }
            }
        }
        cout << dp[s][g] + dp[g][d] << " " << dp[s][d] - dp[s][g] - dp[g][d] << endl;
    }
    return 0;
}


