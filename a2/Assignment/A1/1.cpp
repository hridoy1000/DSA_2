#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int arr[N];
int i = 0;
int start,endd;

int maxSubArray(int arr[],int n)
{
    int maxx,cSum;
    maxx=cSum=start=endd=0;
    for(int i = 1; i<=n; i++)
    {
        cSum+=arr[i];
        if(cSum>maxx)
        {
            endd = i;
            maxx = cSum;
        }
        if(cSum < 0)
        {
            start = i;
            cSum = 0;
        }
    }
    return maxx;
}

int main()
{
    int n;
    //cout << "What is size of the array?\n--> ";
    cin >> n;
    //cout << "Enter the elements of the array--> ";
    for(int i = 1; i<=n; i++) /// Array index starts from 1<=n.
    {
        cin >> arr[i];
    }
    int result = maxSubArray(arr,n);
    //cout << "\nMaximum subarray found in index " << start << " to " << endd << endl;
    //cout << "\nSub array is-> [";
    for(int i = start ;i<endd; i++){
        //cout << arr[i];
        if(i!=endd){
           // cout << ",";
        }
    }
    //cout << "]\n\nMaximum is--> " << result << endl;
    cout << result;
}
