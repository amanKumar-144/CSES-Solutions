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
pii parent[N][N];
int distanceArray[N][N];
bool checkA[N][N];

int n,m;
vector<pii>monsterIndex;
int startX,startY;
int endX,endY;

int valid=1;

void bfsMonster()
{
    //Coordinate,Distance
    deque<pair<pii,int>>dq;
    for(int i=0;i<monsterIndex.size();i++)
    {
        dq.pb(mp(monsterIndex[i],0));
        check[monsterIndex[i].fi][monsterIndex[i].se]=true;
        distanceArray[monsterIndex[i].fi][monsterIndex[i].se]=0;
    }
    
    while(dq.size()>0)
    {
        pair<pii,int>h=dq.front();
        dq.pop_front();
        pii top=h.fi;
        int i=top.fi;
        int j=top.se;
        int dist=h.se;
        distanceArray[i][j]=min(distanceArray[i][j],dist);
       
        if(i-1>=0 && check[i-1][j]==false && graph[i-1][j]!='#')
        {
            if(check[i-1][j]==false)
            {
                check[i-1][j]=true;
                dq.pb(mp(mp(i-1,j),dist+1));
                distanceArray[i-1][j]=dist+1;
            }
            else
            {
                distanceArray[i-1][j]=min(distanceArray[i-1][j],dist+1);
            }
        }
        if(i+1<n && check[i+1][j]==false && graph[i+1][j]!='#')
        {
            if(check[i+1][j]==false)
            {
                check[i+1][j]=true;
                dq.pb(mp(mp(i+1,j),dist+1));
                distanceArray[i+1][j]=dist+1;
            }
            else
            {
                distanceArray[i+1][j]=min(distanceArray[i+1][j],dist+1);
            }
        }
        if(j+1<m && check[i][j+1]==false && (graph[i][j+1]!='#'))
        {
            if(check[i][j+1]==false)
            {
                check[i][j+1]=true;
                dq.pb(mp(mp(i,j+1),dist+1));
                distanceArray[i][j+1]=dist+1;
            }
            else
            {
                distanceArray[i][j+1]=min(distanceArray[i][j+1],dist+1);
            }
        }
        if(j-1>=0 && check[i][j-1]==false && (graph[i][j-1]!='#'))
        {
            if(check[i][j-1]==false)
            {
                check[i][j-1]=true;
                dq.pb(mp(mp(i,j-1),dist+1));
                distanceArray[i][j-1]=dist+1;
            }
            else
            {
                distanceArray[i][j-1]=min(distanceArray[i][j-1],dist+1);
            }
        }
    }
}

int bfsA(int i,int j)
{
    int time=0;
    deque<pair<pii,int>>dq;
    dq.push_back(mp(mp(i,j),time));
    checkA[i][j]=true;
    if(i==0 || i==n-1 || j==0 || j==m-1)return 2;

    while(dq.size()>0)
    {
        pair<pii,int>h=dq.front();
        pii top=h.fi;
        dq.pop_front();
        i=top.fi;
        j=top.se;
        time=h.se;

        //We reached the boundary
        if(i-1==0 && graph[i-1][j]=='.' && distanceArray[i-1][j]>time+1)
        {
            endX=i-1;endY=j;
            parent[i-1][j]=mp(i,j);
            return 1;
        }
        if(i+1==n-1 && graph[i+1][j]=='.' && distanceArray[i+1][j]>time+1)
        {
            endX=i+1;endY=j;
            parent[i+1][j]=mp(i,j);
            return 1;
        }
        if(j-1==0 &&graph[i][j-1]=='.' && distanceArray[i][j-1]>time+1)
        {
            endX=i;endY=j-1;
            parent[i][j-1]=mp(i,j);
            return 1;
        }
        if(j+1==m-1 &&graph[i][j+1]=='.' && distanceArray[i][j+1]>time+1)
        {
            endX=i;endY=j+1;
            parent[i][j+1]=mp(i,j);
            return 1;
        }

        if(i-1>=0 && checkA[i-1][j]==false && (graph[i-1][j]!='#') && distanceArray[i-1][j]>time+1)
        {
            checkA[i-1][j]=true;
            parent[i-1][j]=mp(i,j);
            dq.pb(mp(mp(i-1,j),time+1));
        }
        //Go Down
        if(i+1<n && checkA[i+1][j]==false && (graph[i+1][j]!='#') && distanceArray[i+1][j]>time+1)
        {
            checkA[i+1][j]=true;
            parent[i+1][j]=mp(i,j);
            dq.pb(mp(mp(i+1,j),time+1));
        }
        //Go right
        if(j+1<m && checkA[i][j+1]==false && (graph[i][j+1]!='#') && distanceArray[i][j+1]>time+1)
        {
            checkA[i][j+1]=true;
            parent[i][j+1]=mp(i,j);
            dq.pb(mp(mp(i,j+1),time+1));
        }
        //Go left
        if(j-1>=0 && checkA[i][j-1]==false && (graph[i][j-1]!='#') && distanceArray[i][j-1]>time+1)
        {
            checkA[i][j-1]=true;
            parent[i][j-1]=mp(i,j);
            dq.pb(mp(mp(i,j-1),time+1));
        }
    }
    return 0;
}


int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            distanceArray[i][j]=LLONG_MAX;
            char x;cin>>x;
            graph[i][j]=x;
            check[i][j]=false;
            checkA[i][j]=false;
            parent[i][j]=mp(-1,-1);
            if(graph[i][j]=='M')monsterIndex.pb(mp(i,j));
            if(graph[i][j]=='A')
            {
                startX=i;startY=j;
            }
        }
    }
    bfsMonster();
    
    parent[startX][startY]=mp(startX,startY);
    valid=bfsA(startX,startY);
    if(valid==0)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        if(valid==2)
        {
            cout<<0<<endl;
            return 0;
        }
        pii a=mp(endX,endY);
        vector<pii>ans;
        while(!(a.fi==startX && a.se==startY))
        {
            ans.pb(a);
            a=parent[a.fi][a.se];
        }
        if(ans.size()>0)
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