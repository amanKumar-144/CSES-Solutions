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
const int N=100001;
int dp1[N];//Prev State
int dp2[N];//Next State
int n,x;
vector<pii>pricePages;

int32_t main()
{
    FAST;
    cin>>n>>x;
    vii a;
    vii b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        b.pb(x);
    }
    for(int i=0;i<n;i++){
        pricePages.pb(mp(a[i],b[i]));
    }
    pricePages.pb(mp(0,0));
    sort(pricePages.begin(),pricePages.end());

    for(int j=1;j<pricePages.size();j++)
    {
        int cost=pricePages[j].fi;
        int pages=pricePages[j].se;

        for(int i=1;i<=x;i++)//Price List
        {
            if(cost>i)
            {
                dp2[i]=dp1[i];
            }
            else
            {
                //Include
                dp2[i]=max(dp2[i],pages+dp1[i-cost]);
                
                //Don't Include
                dp2[i]=max(dp2[i],dp1[i]);
            }
        }
        for(int i=1;i<=x;i++)
            dp1[i]=dp2[i];
    }
    cout<<dp2[x]<<endl;
    return 0;
}