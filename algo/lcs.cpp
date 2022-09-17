// Longest Common Subsequence (LCS) Algorithm

#include<iostream>
using namespace std;

void lcs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[m+1];
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
}

//explaination of the code
// 1. create a 2D array of size (n+1)*(m+1) and initialize it with 0
// 2. traverse the 2D array from 1 to n and 1 to m
// 3. if the characters at i-1 and j-1 are equal, then dp[i][j] = 1 + dp[i-1][j-1]
// 4. else, dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// 5. print dp[n][m]


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
    return 0;
}
