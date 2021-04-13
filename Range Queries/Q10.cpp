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
const int INF=1e9;
const int MAXN=200001;

pair<int, int> maxSegmentTree[4*MAXN];//Max Segment Tree
pair<int, int> minSegmentTree[4*MAXN];//Min Segment Tree
int n;
vii a;

pii combineMin(pii a, pii b) 
{
    if (a.first < b.first) 
        return a;
    if (b.first < a.first)
        return b;
    return mp(a.first, a.second + b.second);
}
pii combineMax(pii a, pii b) 
{
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return mp(a.first, a.second + b.second);
}

void build(vii &a, int v, int tl, int tr) 
{
    if(tl == tr) 
    {
        maxSegmentTree[v] = mp(a[tl], 1);
        minSegmentTree[v] = mp(a[tl], 1);
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        maxSegmentTree[v] = combineMax(maxSegmentTree[v*2], maxSegmentTree[v*2+1]);
        minSegmentTree[v] = combineMin(minSegmentTree[v*2], minSegmentTree[v*2+1]);
    }
}
pii get_min(int v, int tl, int tr, int l, int r) 
{
    if (l > r)
        return make_pair(INF, 0);
    if (l == tl && r == tr)
        return minSegmentTree[v];
    int tm = (tl + tr) / 2;
    return combineMin(get_min(v*2, tl, tm, l, min(r, tm)), get_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}
pii get_max(int v, int tl, int tr, int l, int r) 
{
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return maxSegmentTree[v];
    int tm = (tl + tr) / 2;
    return combineMax(get_max(v*2, tl, tm, l, min(r, tm)), get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
    if(tl == tr) 
    {
        maxSegmentTree[v] = make_pair(new_val, 1);
        minSegmentTree[v] = make_pair(new_val, 1);
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);

        maxSegmentTree[v] = combineMax(maxSegmentTree[v*2], maxSegmentTree[v*2+1]);
        minSegmentTree[v] = combineMin(minSegmentTree[v*2], minSegmentTree[v*2+1]);
    }
}
int32_t main()
{
    FAST;
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }

    build(a,1,0,n-1);
    return 0;
}