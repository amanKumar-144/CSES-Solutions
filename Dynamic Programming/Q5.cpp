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
const int N=1000001;
int dp[N];
int calculate(int n)
{
    vii getDigits;
    int copy=n;
    while(copy>0)
    {
        getDigits.pb(copy%10);
        copy/=10;
    }
    if(getDigits.size()==1)
    {
        dp[getDigits[0]]=1;
        return dp[getDigits[0]];
    }
    for(int i=0;i<getDigits.size();i++)
    {
        if(getDigits[i]!=0)
        {
            if(dp[n-getDigits[i]]!=LLONG_MAX)
                dp[n]=min(dp[n],1+dp[n-getDigits[i]]);
            else
            {
                dp[n-getDigits[i]]=calculate(n-getDigits[i]);
                dp[n]=min(dp[n],1+dp[n-getDigits[i]]);
            }
        }
    }
    return dp[n];
}
int32_t main()
{
    FAST;
    int n;
    cin>>n;
    for(int i=n;i>=0;i--)dp[i]=LLONG_MAX;
    dp[n]=calculate(n);
    cout<<dp[n]<<endl;
    return 0;
}