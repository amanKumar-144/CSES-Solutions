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
const int N=1001;
char graph[N][N];
bool check[N][N];
int n,m;
pii parent[N][N];
int valid=0;


int bfs(int i,int j)
{
    deque<pii>dq;
    dq.push_back(mp(i,j));
    while(dq.size()>0)
    {
        pii top=dq.front();
        dq.pop_front();
        i=top.fi;
        j=top.se;
        check[i][j]=true;
        if(graph[i][j]=='B')return 1;

        if(i-1>=0 && check[i-1][j]==false && (graph[i-1][j]=='.' || graph[i-1][j]=='B'))
        {
            parent[i-1][j]=mp(i,j);
            check[i-1][j]=true;
            dq.pb(mp(i-1,j));
        }
        //Go Down
        if(i+1<n && check[i+1][j]==false && (graph[i+1][j]=='.' || graph[i+1][j]=='B'))
        {
            parent[i+1][j]=mp(i,j);
            check[i+1][j]=true;
            dq.pb(mp(i+1,j));
        }
        //Go right
        if(j+1<m && check[i][j+1]==false && (graph[i][j+1]=='.' || graph[i][j+1]=='B'))
        {
            parent[i][j+1]=mp(i,j);
            check[i][j+1]=true;
            dq.pb(mp(i,j+1));
        }
        //Go left
        if(j-1>=0 && check[i][j-1]==false && (graph[i][j-1]=='.' || graph[i][j-1]=='B'))
        {
            parent[i][j-1]=mp(i,j);
            check[i][j-1]=true;
            dq.pb(mp(i,j-1));
        }
    }
    return 0;
}

int32_t main()
{
    FAST;
    cin>>n>>m;
    int startX,startY;
    int endX,endY;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char x;cin>>x;
            graph[i][j]=x;
            parent[i][j]=mp(-1,-1);
            check[i][j]=false;
            if(x=='A')
            {
                startX=i;startY=j;
            }
            if(x=='B')
            {
                endX=i;endY=j;
            }
        }
    }
    parent[startX][startY]=mp(startX,startY);
    valid=bfs(startX,startY);


    if(valid==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        pii a=mp(endX,endY);
        vector<pii>ans;
        while(!(a.fi==startX && a.se==startY))
        {
            ans.pb(a);
            a=parent[a.fi][a.se];
        }
        reverse(ans.begin(),ans.end());

        int x=startX;
        int y=startY;
        string hi;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].fi==startX-1 && startY==ans[i].se)hi.pb('U');
            if(ans[i].fi==startX+1 && startY==ans[i].se)hi.pb('D');
            if(ans[i].fi==startX && startY-1==ans[i].se)hi.pb('L');
            if(ans[i].fi==startX && startY+1==ans[i].se)hi.pb('R');

            startX=ans[i].fi;
            startY=ans[i].se;
        }
        cout<<hi.size()<<endl;
        cout<<hi<<endl;
    }
    return 0;
}