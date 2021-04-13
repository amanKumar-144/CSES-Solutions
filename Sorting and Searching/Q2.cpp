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
    int n,m,k;cin>>n>>m>>k;
    vii a;
    vii b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b.pb(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans=0;
    int bPtr=0;
    for(int i=0;i<n && bPtr<m;)
    {
        if(a[i]-k<=b[bPtr] && b[bPtr]<=a[i]+k)
        {
            ans++;
            bPtr++;
            i++;
        }
        else if(a[i]-k>b[bPtr])bPtr++;
        else if(a[i]+k<b[bPtr])i++;
    }
    cout<<ans<<endl;
    return 0;
}