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
int lazy[4*N];

void build(vii &a, int v, int tl, int tr) 
{
    if (tl == tr) 
    {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r, int add) 
{
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}
int get(int v, int tl, int tr, int pos) 
{
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    build(a,1,0,n-1);
    for(int i=1;i<=m;i++)
    {
        int p;cin>>p;
        if(p==1)
        {
            int a,b,u;cin>>a>>b>>u;
            a--;b--;
            update(1,0,n-1,a,b,u);
        }
        else if(p==2)
        {
            int k;cin>>k;
            k--;
            int val=get(1,0,n-1,k);
            cout<<val<<"\n";
        }
    }
    return 0;
}