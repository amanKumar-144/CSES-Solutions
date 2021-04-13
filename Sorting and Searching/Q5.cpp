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
const int N=400001;
vector<pii>store;
map<int,int>conversion;
vector<int>pathMap(N,0);

int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        store.pb(mp(x,y));
        a.pb(x);
        a.pb(y);
    }
    sort(a.begin(),a.end());
    int counter=0;
    for(int i=0;i<a.size();i++)
    {
        conversion.ins(mp(a[i],counter));
        counter++;
    }
    for(int i=0;i<store.size();i++)
    {
        auto x=conversion.find(store[i].fi);
        auto y=conversion.find(store[i].se);
        pathMap[x->se]+=1;
        pathMap[y->se+1]-=1;
    }
    int ans=pathMap[0];
    for(int i=1;i<N;i++)
    {
        pathMap[i]=pathMap[i]+pathMap[i-1];
        ans=max(ans,pathMap[i]);
    }
    cout<<ans<<endl;
    return 0;
}