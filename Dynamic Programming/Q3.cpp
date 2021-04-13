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
const int MOD=1e9+7;
const int N=1000001;
int dp[N];
int n,m;
int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=0;i<=m;i++)
    {
        dp[i]=0;
    }
    vii a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
    }
    sort(a.begin()+1,a.end());
    
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int available=a[i];
            if(available==j)dp[j]++;
            else if(j>available)dp[j]=dp[j]+dp[j-available];
            
            dp[j]+=MOD;
            dp[j]%=MOD;
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}