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
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    vii b(n+1,0);
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
        b[x]=i+1;
    }
    int ans=1;
    for(int i=1;i<=n-1;i++)
    {
        if(b[i]<b[i+1])continue;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}