#include <bits/stdc++.h>

using namespace std;

void LCS(char *X, char *Y, int lengthx, int lengthy)
{
    int L[lengthx +1] [lengthy+1];
    for (int i=0; i<=lengthx; i++)
    {
        for (int j=0; j<=lengthy; j++)
        {
            if(i==0 || j ==0)
                L[i][j] = 0;
            else if (X[i]==Y[j])
                L[i][j] =L[i-1][j-1]+1;
            else
                L[i][j] =max(L[i][j-1],L[i-1][j]);
        }
    }
    int length_lcs=L[lengthx][lengthy];
    cout << "Length of the LCS : "<< length_lcs << endl << endl ;


    /// Finding out the LCS

    char LCS[length_lcs];
    LCS[length_lcs] ='\0';
    int index = length_lcs-1;
    int i =lengthx;
    int j =lengthy;

    while (i>0 && j>0)
    {
        if (X[i-1]==Y[j-1])
        {
            cout<< "Diagonal Traverse" << endl;
            LCS[index] = X[i-1];
            index--;
            i--;
            j--;
        }
        ///else if (L[i-1][j]>L[i][j-1]) /// Top == Left
                ///Dual Probality or Branching of more LCS
                /// Multiple Array or Vector
        else if (L[i-1][j]>L[i][j-1]) /// Top > Left
        {
            cout<< "Top Traverse" << endl; /// Top Traverse
            i--;

        }
        else /// Left > Top
        {
            cout<<"Left Traverse" <<endl;
            j--;

        }
    }

    cout << endl<< "LCS of " << X << " and " << Y << " : " << LCS;

}

int main()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    int m = strlen(X);
    int n = strlen(Y);
    LCS (X,Y,m,n);
    return 0;
}
