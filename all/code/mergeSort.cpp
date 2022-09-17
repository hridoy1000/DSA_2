#include<bits/stdc++.h>

using namespace std;

void MERGE(int A[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid+1;
    int k =0;
    int len = ub-lb+1;
    int B[len];

    while(i<=mid && j<=ub) ///Conventional Comparison
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            B[k]=A[j];
            j++;
        }

        k++;
    }
    if(j>ub) ///j DEAD
    {
        while(i<=mid)
        {
            B[k]=A[i];
            i++;
            k++;
        }
    }
    if(i>mid) ///i DEAD
    {
        while(j<=ub)
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }

    ///Transfer to A
    k=0;
    for(int i=lb;i<=ub;i++){
        A[i]=B[k];
        k++;
    }


}
void MERGESORT(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(ub+lb)/2;
        MERGESORT(arr,lb,mid);
        MERGESORT(arr,mid+1,ub);
        MERGE(arr, lb, mid, ub);
    }
}
void PRINTARRAY(int arr[],int len)
{
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr [] = {1,2,100,4,9,34,2,11,88};
    int len = sizeof(arr)/sizeof(arr[0]);
    MERGESORT(arr,0,len-1);
    PRINTARRAY(arr,len);

}
