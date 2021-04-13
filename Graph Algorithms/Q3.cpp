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
const int N=100001;
vector<int>graph[N];
vector<bool>check(N,false);
void dfs(int s)
{
    check[s]=true;
    for(int i=0;i<graph[s].size();i++)
    {
        if(check[graph[s][i]]==false)
        {
            dfs(graph[s][i]);
        }
    }
}
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    vii ans;
    
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            dfs(i);
            ans.pb(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++)
    {
        cout<<ans[0]<<" "<<ans[i]<<endl;
    }
    return 0;
}