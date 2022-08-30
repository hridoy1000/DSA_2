#include<bits/stdc++.h>

using namespace std;

int find_min(int arr[], int n)
{
    if(n==1)
        return arr[0];
    else
       return min(arr[n-1],find_min(arr,n-1));
}


int main()
{
    int arr [] = {1,4,3,-50,8,2,100};
    int len = sizeof(arr)/ sizeof(arr[0]);
    int minimum = find_min(arr,len);
    cout<< minimum;
}
