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
void bfs(int start)
{
    deque<int>dq;
    dq.pb(start);
    while(dq.size()>0)
    {
        int v=dq.front();
        dq.pop_front();
        check[v]=true;
        for(int i=0;i<graph[v].size();i++)
        {
            int child=graph[v][i];
            if(check[child]==false)
            {
                dq.pb(child);
                check[child]=true;
                parent[child]=v;
            }
        }
    }
}
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    parent[1]=1;
    bfs(1);
    if(parent[n]==-1)cout<<"IMPOSSIBLE"<<endl;
    else 
    {
        int last=n;
        vii ans;
        while(last!=1)
        {
            ans.pb(last);
            last=parent[last];
        }
        ans.pb(1);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        print(ans);
    }
    return 0;
}