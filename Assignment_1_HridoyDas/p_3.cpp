#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<a[i]<<endl;
            count++;
        }
    }
    cout<<"unique elements: "<<count<<endl;
    return 0;
}