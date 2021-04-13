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
#define endl "\n"
using namespace std;
const int N=100005;
int dp[N][105];//(Length of Array,Last number)
const int MOD=1e9+7;
int n,m;
vii a(N,0);
int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //Initialization
    if(a[1]==0)
    {
        for(int i=1;i<=m;i++)dp[1][i]=1;
    }
    else 
    {
        dp[1][a[1]]=1;
        for(int i=1;i<=m;i++)
        {
            if(i!=a[1])dp[1][i]=0;
        }
    }

    for(int i=2;i<=n;i++)//Digit Lengths
    {
        if(a[i]==0)
        {
            for(int digit=1;digit<=m;digit++)
            {
                dp[i][digit]=max(dp[i-1][digit-1],0ll)+max(dp[i-1][digit],0ll)+max(dp[i-1][digit+1],0ll);
                dp[i][digit]%=MOD;
            }
        }
        else if(a[i]!=0)
        {
            int digit=a[i];
            dp[i][digit]=max(dp[i-1][digit-1],0ll)+max(dp[i-1][digit],0ll)+max(dp[i-1][digit+1],0ll);
            dp[i][digit]%=MOD;

            for(int j=1;j<=m;j++)
            {
                if(j!=digit)dp[i][j]=0;
            }
        }
    }
    int ans=0;
    if(a[n]!=0)
    {
        ans=dp[n][a[n]];
        ans%=MOD;
    }
    else if(a[n]==0)
    {
        for(int i=1;i<=m;i++)
        {
            ans+=max(dp[n][i],0ll);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}