#include<iostream>
using namespace std;

void reverse(char arr[],int n){
    if(n==1){
        return;
    }
    reverse(arr,n-1);
    cout<<arr[n-1];

}

int main(){
    char arr[100];
    int n;
     cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter The array: ";
    for( int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;

    reverse(arr,n);
    cout<<"Reversed array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}
