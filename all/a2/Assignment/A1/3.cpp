#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
int arr[N];


void mergee(int arr[],int lb,int mid,int ub)
{
    int i = lb;
    int j = mid+1;
    int k =0;
    int len = ub-lb+1;
    int arr2[len];

    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            arr2[k]=arr[i];
            i++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;
        }
        k++;
    }

    if(j>ub)
    {
        while(i<=mid)
        {
            arr2[k]=arr[i];
            i++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            arr2[k]=arr[j];
            j++;
            k++;
        }
    }

    k = 0;
    for(int i=lb;i<=ub;i++)
    {
        arr[i]=arr2[k];
        k++;
    }
}

void mSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(ub+lb)/2;
        mSort(arr,lb,mid);
        mSort(arr,mid+1,ub);
        mergee(arr,lb,mid,ub);
    }
}

int removeDuplicate(int arr[], int n)
{
    int prev = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]!= arr[prev])
        {
            arr[++prev] = arr[i];
        }
    }
    prev = prev+1;

    return prev;
}


int main()
{
    int n;
    //cout << "What is size of the array?\n--> ";
    cin >> n;
    //cout << "Enter the elements of the array--> ";
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int k;
    //cout << "Input the value of k--> ";
    cin >> k;

    mSort(arr,0,n-1);

    for(int i = 0; i<n; i++)
    {
         if(i==n-k)
         {
             //cout << "--> " << arr[i];
             cout <<  arr[i];
             break;
         }
    }

/**

    sort(arr,arr+n,greater<int>());

    for(int i = 0; i<n; i++)
    {
         if(i==k-1)
         {
             cout << "--> " << arr[i];
             break;
         }
    }

    */


/**

    int result = removeDuplicate(arr,n);

    for(int i = 0; i<result; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    for(int i = 0; i<result; i++)
    {
         if(i==k-1)
         {
             cout << "--> " << arr[i];
             break;
         }
    }

*/


}

