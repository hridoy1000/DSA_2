#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    float sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum=sum+x;
    }
    float average;
    average= sum/n;
    cout<< "average of the numbers : " << average;
    return 0;
}


/// Input n, initialize sum = 0
/// For (1 to n)
///     take new input
///     add the input to sum and store the new value in sum
/// average = sum / n
