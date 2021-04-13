#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000001;
int dp[N];
int n,m;
int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=0;i<=m;i++)
    {
        dp[i]=LLONG_MAX;
    }
    vii a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=m;i++)
    {
        if(i%a[1]==0)dp[i]=i/a[1];
    }
    for(int i=2;i<=n;i++)
    {
        int available=a[i];
        for(int j=1;j<=m;j++)
        {
            if(j-available==0)dp[j]=1;

            else if(j>available && dp[j-available]!=LLONG_MAX)dp[j]=min(dp[j],1+dp[j-available]);
        }
    }
    if(dp[m]==LLONG_MAX)cout<<-1<<endl;
    else cout<<dp[m]<<endl;
    return 0;
}