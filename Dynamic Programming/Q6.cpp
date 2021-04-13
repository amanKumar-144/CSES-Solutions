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
const int N=1001;
const int MOD=1e9+7;
int dp[N][N];
int visit[N][N];
int n;
vector<string>grid;
int calculatePaths(int i,int j)
{
    if(grid[i][j]=='*')
    {
        dp[i][j]=0;
        visit[i][j]=1;
        return dp[i][j];
    }
    else if(i==0 && j==0)
    {
        visit[i][j]=1;
        dp[i][j]=1;
        return 1;
    }
    else
    {
        if(i-1>=0 && grid[i-1][j]=='.')
        {
            if(dp[i-1][j]==0 && visit[i-1][j]==0)
            {
                visit[i-1][j]=1;
                dp[i-1][j]=calculatePaths(i-1,j);
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        }
        if(j-1>=0 && grid[i][j-1]=='.')
        {
            if(dp[i][j-1]==0 && visit[i][j-1]==0)
            {
                visit[i][j-1]=1;
                dp[i][j-1]=calculatePaths(i,j-1);
            }
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
        visit[i][j]=1;
        return dp[i][j];
    }
}
int32_t main()
{
    FAST;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        grid.pb(s);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
            visit[i][j]=0;
        }
    }

    dp[n-1][n-1]=calculatePaths(n-1,n-1);
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}