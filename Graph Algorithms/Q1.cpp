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
const int N=2001;
char graph[N][N];
bool check[N][N];
int n,m;
void dfs(int i,int j)
{
    check[i][j]=true;
    //Go UP
    if(i-1>=0 && check[i-1][j]==false && graph[i-1][j]=='.')dfs(i-1,j);
    //Go Down
    if(i+1<n && check[i+1][j]==false && graph[i+1][j]=='.')dfs(i+1,j);
    //Go right
    if(j+1<m && check[i][j+1]==false && graph[i][j+1]=='.')dfs(i,j+1);
    //Go left
    if(j-1>=0 && check[i][j-1]==false && graph[i][j-1]=='.')dfs(i,j-1);
}

int32_t main()
{
    FAST;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char x;cin>>x;
            graph[i][j]=x;
            check[i][j]=false;
        }
    }
    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(check[i][j]==false && graph[i][j]=='.')
            {
                answer++;
                dfs(i,j);
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}