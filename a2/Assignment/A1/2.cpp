#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
int arr[N],coutt[N];

int main()
{
    int n,cot=0;
    //cout << "What is size of the array?\n--> ";
    cin >> n;
    //cout << "Enter the elements of the array--> ";
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i<n ; i++){
        for(int j = i+1; j<n ;j++)
        {
            if(arr[i]>arr[j]) cot++;
        }
    }

    //cout << "--> " << cot;
    cout << cot;



}

/**
-------------------Time Complexity O(nlogn)-------------------
---------------------Using Fenwick Tree-----------------------


#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll int,ll int>
#define PI 2*acos(0)
#define mx 1000006
#define INF 1e15
#define all(x) x.begin() , x.end()
using namespace std;


ll n ;
vector< ll > tree ;

ll sum(ll idx){
    ll s = 0 ;
    while(idx > 0){
        s += tree[idx] ;
        idx -= (idx & (-idx)) ;
    }
    return s ;
}

void update(ll idx , ll val){
    while(idx <= n){
        tree[idx] += val ;
        idx += (idx & (-idx)) ;
    }
}

int main()
{
    ll tc,m,i,j,k;
    cout << "What is size of the array?\n--> ";
    cin >> n;
    cout << "Enter the elements of the array--> ";
    tree = vector< ll > (n + 1 , 0) ;
    vector< ll > a(n) , b(n) ;
    map< ll , deque< ll > > pos ;

    for(i = 0 ; i < n ; i ++ ){
            cin >> a[i] ;
            b[i] = a[i] ;
    }
    sort(all(b)) ;

    for(i = 0 ; i < n ; i ++ ){
        pos[b[i]].push_back(i) ;
    }

    ll ans = 0 ;

    for(i = 0 ; i < n ; i ++ ){
        j = pos[a[i]].front() ;
        k = sum(j + 1) ;
        ans += max(i - k , 0LL) ;
        pos[a[i]].pop_front() ;
        update(j + 1 , 1LL) ;
    }

    cout << "--> " << ans ;
    return 0;
}
*/
