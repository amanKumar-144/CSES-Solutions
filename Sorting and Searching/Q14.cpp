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
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vii storeBuilding(n,0);
    storeBuilding[0]=a[0];
    int start=0;int end=0;
    for(int i=1;i<n;i++)
    {
        if(storeBuilding[end]<=a[i])
        {
            storeBuilding[end+1]=a[i];
            end++;
        }
        else
        {
            int pos=end;
            int copyStart=start;
            int copyEnd=end;
            while(copyStart<=copyEnd)
            {
                int middle=copyStart+(copyEnd-copyStart)/2;
                if(storeBuilding[middle]>a[i])//Go left
                {
                    pos=middle;
                    copyEnd=middle-1;
                }
                else if(storeBuilding[middle]<=a[i])//Go right
                {
                    copyStart=middle+1;
                }
            }
            storeBuilding[pos]=a[i];
        }
    }cout<<end+1<<endl;
    return 0;
}