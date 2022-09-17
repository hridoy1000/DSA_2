#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
   ll n;
   string s,t;
   cin>>n>>s>>t;
   ll i,last=-1,total=0;
   for(i=0; i<n; i++) {
      if(s[i]==t[i]) {
         last=-1;
      }
      else if(last==-1 or s[i]!=s[last]) {
         total++;
         last=i;
      }
   }
   cout<<total <<"\n";
}
