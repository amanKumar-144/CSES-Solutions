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
    int n,capacity;
    cin>>n>>capacity;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    int start=0;int end=n-1;
    int ans=0;
    while(start<end)
    {
        if(a[start]+a[end]<=capacity)
        {
            start++;end--;
            ans++;
        }
        else if(a[start]+a[end]>capacity)
        {
            a[end]=-1;
            end--;
        }
        if(start==end)
        {
            a[end]=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==-1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}