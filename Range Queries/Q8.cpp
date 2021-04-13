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
int n,m;
vii a;
void build(vii &a, int v, int tl, int tr) 
{
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) 
{
    if (tl == tr) 
    {
        t[v] = new_val;
        a[pos]=new_val;
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2],t[v*2+1]);
 
    }
}

int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t[v] < x) return -1;
        while(lv != rv) 
        {
            int mid = lv + (rv-lv)/2;
            if(t[2*v] >= x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return rv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}

void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}

int32_t main()
{
    FAST;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    build(a,1,0,n-1);
    vii groups;
    vii answers;

    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        groups.pb(x);
    }
    for(int i=0;i<m;i++)
    {
        int x=groups[i];
        int val=get_first(1,0,n-1,0,n-1,x);//Will give the index
        if(val==-1)answers.pb(0);
        else
        {
            int value=a[val];
            value=value-groups[i];
            update(1,0,n-1,val,value);
            answers.pb(val+1);
        }
    }
    print(answers);
    return 0;
}