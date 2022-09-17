#include<iostream>
using namespace std;

string reverse(string str){
    if(str.length()==1){
        return str;
    }
    return reverse(str.substr(1))+str[0];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        cout<<reverse(str)<<endl;
    }
    return 0;
    
}

