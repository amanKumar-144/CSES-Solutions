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
int32_t main()
{
    FAST;
    int n;cin>>n;
    int m;cin>>m;

    vii a(n+1,0);
    vii b(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
        b[x]=i;
    }
    int ans=1;
    for(int i=1;i<=n-1;i++)
    {
        if(b[i]<b[i+1])continue;
        else ans++;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        //Check 4 places
        int valueX=a[x];//Index
        int valueY=a[y];//Index
        //b[valueX]=y;
        //b[valueY]=x;

        if(valueX-1>=0)
        {
            if(b[valueX-1]>b[valueX])ans--;
        }
        if(valueX+1<=n)
        {
            if(b[valueX]>b[valueX+1])ans--;
        }
        b[valueX]=y;
        if(valueX-1>=0)
        {
            if(b[valueX-1]>b[valueX])ans++;
        }
        if(valueX+1<=n)
        {
            if(b[valueX]>b[valueX+1])ans++;
        }


        if(valueY-1>=0)
        {
            if(b[valueY-1]>b[valueY])ans--;
        }
        if(valueY+1<=n)
        {
            if(b[valueY]>b[valueY+1])ans--;
        }
        b[valueY]=x;
        if(valueY-1>=0)
        {
            if(b[valueY-1]>b[valueY])ans++;
        }
        if(valueY+1<=n)
        {
            if(b[valueY]>b[valueY+1])ans++;
        }

        cout<<ans<<endl;
        swap(a[x],a[y]);
    }
    return 0;
}