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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int32_t main()
{
    FAST;
    ordered_set s;
    s.ins(mp(1,1));
    s.ins(mp(1,2));
    s.ins(mp(1,3));
    s.ins(mp(1,4));
    s.ins(mp(1,5));
    s.ins(mp(1,6));

    int pos=s.order_of_key(mp(1,7));
    cout<<pos<<endl;
    return 0;
}