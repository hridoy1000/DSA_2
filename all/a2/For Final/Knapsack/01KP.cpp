 #include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K [n+1][W+1];
    ///vector<int>parent;
    ///vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) ///Intialisation
                K[i][w] = 0;
            else if (wt[i - 1] <= w) ///ITEM TAKEN
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            /// WHAT IF THE QUESTION ASKED FOR THE ITEMS THAT HAVE BEEN TAKEN BY THE THIEF
            /// FOR EXAMPLE IF THE THIEF HAS TAKEN First and Third Item PRINT (1,0,1,0)
            /// YOU NEED TO EDIT CODE IN THIS BLOCK
            else ///ITEM NOT TAKEN
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
    int val[] = {2,3,1,4};
    int wt[] = {3,4,6,5};
    int W = 8;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}

