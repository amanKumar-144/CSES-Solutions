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
vector<int>colourArray(N,-1);
int n,m;
int valid=1;
void bfs(int start)
{
    deque<pii>dq;
    int startColour=1;
    dq.pb(mp(start,startColour));
    colourArray[start]=startColour;

    while(dq.size()>0)
    {
        pii v=dq.front();
        dq.pop_front();
        check[v.fi]=true;
        int colour=v.se;
        
        for(int i=0;i<graph[v.fi].size();i++)
        {
            int child=graph[v.fi][i];
            if(check[child]==false)
            {
                int childColour;
                if(colour==1)childColour=2;
                else if(colour==2)childColour=1;

                colourArray[child]=childColour;
                dq.pb(mp(child,childColour));
                check[child]=true;
                parent[child]=v.fi;
            }
            else
            {
                if(colour==colourArray[child])valid=0;
            }
        }
    }
}
int32_t main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
            bfs(i);
    }
    if(valid==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<colourArray[i]<<" ";
    }cout<<endl;
}