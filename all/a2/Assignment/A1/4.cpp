#include<bits/stdc++.h>
using namespace std;

const int N = 5*1e4;
int arr[N];
int i,j;

int reversePairs(int arr[],int n)
{
    int flag = 0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(arr[i]>arr[j]*2)
            {
                flag++;
            }
        }
    }
    return flag;
}
int main()
{
    int n;
    //cout << "What is size of the array?\n--> ";
    cin >> n;
    //cout << "Enter the elements of the array--> ";
    for(int i = 1; i<=n; i++)
    {
        cin >> arr[i];
    }
    int result = reversePairs(arr,n);
    //cout << "\n--> " << result;
    cout << result;
}
