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
vii a;
vii removedIndexes;
vii indexList;

void build(vii &a, int v, int tl, int tr) 
{
    if(tl == tr) 
    {
        t[v] = a[tl];
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int find_kth(int v, int tl, int tr, int k) 
{
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
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
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        indexList.pb(1);
    }
    build(indexList,1,0,n-1);

    for(int i=0;i<n;i++){
        int x;cin>>x;
        removedIndexes.pb(x);
    }
    for(int i=0;i<removedIndexes.size();i++)
    {
        int k=removedIndexes[i];
        int index=find_kth(1,0,n-1,k);
        update(1,0,n-1,index,0);
        cout<<a[index]<<" ";
    }cout<<endl;
    return 0;
}