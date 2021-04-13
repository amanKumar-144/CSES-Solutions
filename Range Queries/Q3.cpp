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
        t[v] = t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) 
{
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))+sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
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
        int p,x,y;cin>>p>>x>>y;
        x--;y--;
        if(p==1)update(1,0,n-1,x,y+1);
        else if(p==2)
        {
            int val=sum(1,0,n-1,x,y);
            cout<<val<<"\n";
        }
    }
    return 0;
}