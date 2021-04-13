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
vector<pii>storeEdges;

bool comp(pii &a,pii &b)
{
    if(a.se < b.se)return true;
    else if(a.se > b.se)return false;
    else
    {
        if(a.fi<b.fi)return true;
        else return false;
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        storeEdges.pb(mp(x,y));
    }
    sort(storeEdges.begin(),storeEdges.end(),comp);
    int ans=1;
    int backPart=storeEdges[0].se;

    for(int i=1;i<storeEdges.size();i++)
    {
        if(storeEdges[i].fi>=backPart)
        {
            ans++;
            backPart=storeEdges[i].se;
        }
    }
    cout<<ans<<endl;
    return 0;
}