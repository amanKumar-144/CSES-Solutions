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

const int N=5005;
int dp[N][N];//for index (i,j)
int n;
vii a(N,0);

int calculate(int i,int j)
{
    if(i==j)
    {
        dp[i][i]=a[i];
        return dp[i][i];
    }
    //Array [i,j]

    int sum1=a[i];
    if(i+1<=j && dp[i+1][j]==-1)
    {
        dp[i+1][j]=calculate(i+1,j);
        sum1-=dp[i+1][j];
    }
    else if(i+1<=j)sum1-=dp[i+1][j];


    int sum2=a[j];
    if(i<=j-1 && dp[i][j-1]==-1)
    {   
        dp[i][j-1]=calculate(i,j-1);
        sum2-=dp[i][j-1];
    }
    else if(i<=j-1)sum2-=dp[i][j-1];


    dp[i][j]=max(sum1,sum2);
    return dp[i][j];
}
int32_t main()
{
    FAST;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dp[i][j]=-1;
    }
    dp[1][n]=calculate(1,n);
    //[Score1+Score2 + (Score1-Score2)]/2
    cout<<(sum+dp[1][n])/2<<endl;
    return 0;
}