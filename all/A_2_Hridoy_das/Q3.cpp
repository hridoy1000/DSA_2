#include<iostream>
using namespace std;
#define ll long long

int main(){
 vector<pair<ll,ll>> v={{10,16},{2,8},{1,6},{7,12}};
 vector<pair<ll,ll>> v={{1,2},{3,4},{5,6},{7,8}};
     sort(v.begin(),v.end());
     ll ans=0,last=-1;
     for(auto [l,r]:v) if(l>last) {
      ans++;
      last=r;
}
   cout<< ans <<"\n";
}





