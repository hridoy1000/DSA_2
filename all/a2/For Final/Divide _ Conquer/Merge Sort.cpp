#include<bits/stdc++.h>
using namespace std;

void MERGE(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid+1;
    int k =0;
    int len = ub-lb+1;
    int B[len];

    while(i<=mid && j<=ub) ///Conventional Comparison
    {
        if(arr[i]<arr[j])
        {
            B[k]=arr[i];
            i++;
        }
        else
        {
            B[k]=arr[j];
            j++;
        }

        k++;
    }
    if(j>ub) ///j DEAD
    {
        while(i<=mid)
        {
            B[k]=arr[i];
            i++;
            k++;
        }
    }
    if(i>mid) ///i DEAD
    {
        while(j<=ub)
        {
            B[k]=arr[j];
            j++;
            k++;
        }
    }

    ///Transfer to A
    k=0;
    for(int i=lb;i<=ub;i++){
        arr[i]=B[k];
        k++;
    }


}
void mSort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(ub+lb)/2;
        mSort(arr,lb,mid);
        mSort(arr,mid+1,ub);
        MERGE(arr, lb, mid, ub);
    }
}
void pArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int n;
    cout << "Enter the size of the array--> ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements--> ";
    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    cout << "After sorting--> ";
    mSort(arr,0,n-1);
    pArray(arr,n);

}
