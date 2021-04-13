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
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    int ans=-LLONG_MAX;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=a[i];
        if(temp>ans)ans=temp;
        if(temp<0)temp=0;
    }
    cout<<ans<<endl;
    return 0;
}