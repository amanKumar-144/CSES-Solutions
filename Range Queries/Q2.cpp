#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N=200001;
int t[4*N];

void build(vii &a, int v, int tl, int tr) 
{
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}


int minValue(int v, int tl, int tr, int l, int r) 
{
    if(l>r) 
        return LLONG_MAX;
    if(l==tl && r==tr) 
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    return min(minValue(v*2, tl, tm, l, min(r, tm)),minValue(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    build(a,1,0,n-1);
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        x--;y--;
        int val=minValue(1,0,n-1,x,y);
        cout<<val<<"\n";
    }
    return 0;
}