#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ost;
const int N=200001;

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
    int n;cin>>n;
    int k=1;
    ost s;
    for(int i=1;i<=n;i++)
    {
        s.ins(i);
    }
    int p=k%n;
    vii ans;
    while(s.size()>0)
    {
        int element=*s.find_by_order(p);
        ans.pb(element);
        s.erase(s.find(element));
        if(s.size()>0)
            p=(p+k)%s.size();
    }
    print(ans);
    return 0;
}