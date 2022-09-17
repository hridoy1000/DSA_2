#include<iostream>
#include<bits/stdc++.h>

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter element: ";
        cin>>a;
        sum+=a;
    }
    cout<<"Average is: "<<sum/n<<endl;
    return 0;
}