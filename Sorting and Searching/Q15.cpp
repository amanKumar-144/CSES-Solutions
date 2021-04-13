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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ost;
int32_t main()
{
    FAST;
    int x,n;
    cin>>x>>n;
    vii a;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        a.pb(val);
    }
    ost s;
    map<int,int,greater<int>>dist;
    s.ins(0);s.ins(x);
    dist.ins(mp(x,1));
    for(int i=0;i<n;i++)
    {
        int index=a[i];
        int pos=s.order_of_key(index);//Always greater than 0
    
        int lastVal=*s.find_by_order(pos-1);
        int currentVal=*s.find_by_order(pos);

        auto itr=dist.find(currentVal-lastVal);
        if(itr->se==1)dist.erase(itr);
        else itr->se--;
        
        auto it1=dist.find(index-lastVal);
        if(it1==dist.end())dist.ins(mp(index-lastVal,1));
        else it1->se++;

        auto it2=dist.find(currentVal-index);
        if(it2==dist.end())dist.ins(mp(currentVal-index,1));
        else it2->se++;
       

        s.ins(index);
        cout<<dist.begin()->fi<<" ";
    }cout<<endl;
    return 0;
}