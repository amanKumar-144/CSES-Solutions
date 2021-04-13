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
    int n,k;
    cin>>n>>k;
    vector<pii>a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(mp(x,i+1));
    }
    sort(a.begin(),a.end());
    int ptr1=0;int ptr2=a.size()-1;
    int valid=0;
    while(ptr1<ptr2)
    {
        int val=a[ptr1].fi+a[ptr2].fi;
        if(val>k)
        {
            ptr2--;
        }
        else if(val<k)
        {
            ptr1++;
        }
        else
        {
            valid=1;break;
        }
        if(ptr1==ptr2)break;
    }
    if(valid==1)
    {
        cout<<a[ptr1].se<<" "<<a[ptr2].se<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}