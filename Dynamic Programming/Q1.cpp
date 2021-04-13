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
const int N=1000005;
const int MOD=1e9+7;
vector<int>dp(N,-1);

int construct(int sum)
{
    if(sum==0)
    {
        dp[0]=1;
        return dp[0];
    }
    int ans=0;
    for(int i=1;i<=6;i++)
    {
        if(sum>=i)
        {
            if(dp[sum-i]==-1)
            {
                int val=construct(sum-i);
                val+=MOD;
                val=val%MOD;

                dp[sum-i]=val;
                ans+=val;
                ans%=MOD;
            }
            else
            {
                ans+=dp[sum-i];
                ans+=MOD;
                ans%=MOD;
            }
        }
    }
    dp[sum]=ans;
    return ans;
}
int32_t main()
{
    FAST;
    dp[0]=1;
    int n;cin>>n;
    int answer=construct(n);
    cout<<answer<<endl;
    return 0;
}