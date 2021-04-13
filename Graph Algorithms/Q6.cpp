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
vector<int>parent(N,-1);
int n,m;
int valid=0;
int startV;int endV;
vii ans;
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
 
void dfs(int start,int orig)
{
    check[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        int child=graph[start][i];
        if(check[child]==false)
        {
            parent[child]=start;
            dfs(child,orig);
        }
        else if(check[child]==true && parent[start]!=child )
        {
            //We get a cycle
            valid=1;
            startV=start;
            endV=child;
        }
    }
}
int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false && valid==0)
        {
            parent[i]=i;
            dfs(i,i);
        }
    }
    if(valid==0)cout<<"IMPOSSIBLE"<<endl;
    else
    {
        int v=startV;
        while(v!=endV)
        {
            ans.pb(v);
            v=parent[v];
        }
        ans.pb(endV);
        ans.pb(startV);
 
        cout<<ans.size()<<endl;
        print(ans);
    }
    return 0;
}