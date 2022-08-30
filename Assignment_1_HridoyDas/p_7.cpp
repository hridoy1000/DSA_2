#include<iostream>
using namespace std;
string conv(string s){
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    return s;
}
string remove_ws(string s){
    string s1="";
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            s1+=s[i];
        }
    }
    return s1;
}
int main(){
    string s;
    cin>>s;
    s=conv(s);
    s=remove_ws(s);
    cout<<s;
    return 0;
}
