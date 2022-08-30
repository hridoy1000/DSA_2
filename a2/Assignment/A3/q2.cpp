#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=1e3+7,inf=2e18;
ll t[N],m[N],f[N][N*10][2];
ll n,T,i;

ll dpf(ll i,ll T,ll k) {
   if(T<0) return -inf;
   if(i>n) return 0;
   ll &R=f[i][T][k];
   if(R!=-1) return R;
   R=-inf;
   if(k) R=dpf(i+1,T-t[i],0)+m[i]*2;
   R=max(R,dpf(i+1,T-t[i],k)+m[i]);
   R=max(R,dpf(i+1,T,k));
   return R;
}

int main(){
   cin>>n>>T;
   for(i=1; i<=n; i++) cin>>m[i];
   for(i=1; i<=n; i++) cin>>t[i];
   memset(f,-1,sizeof(f));
   cout<<dpf(1,T,1)<<"\n";
}
