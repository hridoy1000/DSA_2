#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count[n];
    for(int i=0;i<n;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                count[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<count[i]<<endl;
    }
    return 0;
}
