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
int dp1[N];//Prev
int dp2[N];//Current
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }

    sort(a.begin(),a.end());
    dp1[a[0]]=1;
    dp2[a[0]]=1;

    for(int j=1;j<n;j++)
    {
        int element=a[j];
       
        for(int i=1;i<N;i++)
        {
            if(element==i)dp2[i]=1;
            else if(element<i && dp1[i-element]==1)dp2[i]=1;
        }

        for(int i=1;i<N;i++)dp1[i]=dp2[i];
    }
    vii ans;
    for(int i=1;i<N;i++){
        if(dp2[i]==1)ans.pb(i);
    }
    cout<<ans.size()<<endl;
    print(ans);
    return 0;
}