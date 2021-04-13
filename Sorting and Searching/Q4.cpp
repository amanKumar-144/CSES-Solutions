#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> ost;
const int INF=1e9;
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"\n";
    }
}
int32_t main()
{
    FAST;
    ost s;
    int n,m;cin>>n>>m;
    vii a;
    vii customer;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.pb(x);
        s.ins(mp(x,i));
    }

    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        customer.pb(x);
    }
    vii answer;
    for(int i=0;i<m;i++)
    {
        int index=s.order_of_key(mp(customer[i],INF));
        index--;
        if(index==-1)answer.pb(-1);
        else 
        {
            auto itr=s.find_by_order(index);
            //Element,index
            answer.pb(itr->fi);
            s.erase(s.find(mp(itr->fi,itr->se)));   
        }
    }
    print(answer);
    return 0;
}