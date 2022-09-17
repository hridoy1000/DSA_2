#include<bits/stdc++.h>
using namespace std;

int partitionn(int arr[],int lb,int ub)
{
    int pivot = lb;
    int start = lb;
    int endd = ub;
    while(start<endd){
        while(arr[start]<=arr[pivot]){
            start++;
        }
        while(arr[endd]>arr[pivot]){
            endd--;
        }
        if(start<endd){

            swap(arr[start],arr[endd]);
        }
        swap(arr[endd],arr[pivot]);
    }
    return endd;
}

void quick_sort(int arr[], int lb, int ub){
    if(lb<ub)
    {
        int loc = partitionn(arr,lb,ub);
        quick_sort(arr,lb,loc-1);
        quick_sort(arr,loc+1,ub);
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i<n ; i++){
        cout <<  arr[i] << " ";
    }
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
    quick_sort(arr,0,n-1);
    printArray(arr,n);

}
