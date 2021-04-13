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
const int INF=1e9;
const int N=200001;
vii a(N,0);

int32_t main()
{
    FAST;
    ordered_set s;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x;
        s.ins(mp(x,i));
    }

    for(int i=1;i<=m;i++)
    {
        char q;cin>>q;
        if(q=='?')
        {
            int a,b;cin>>a>>b;

            int upperIndex=s.order_of_key(mp(b,INF));
            int lowerIndex=s.order_of_key(mp(a,0));
            cout<<upperIndex-lowerIndex<<endl;
        }
        else
        {
            int index,salary;
            cin>>index>>salary;
            int prevSalary=a[index];
            s.erase(mp(prevSalary,index));
            s.ins(mp(salary,index));
            a[index]=salary;
        }
    }
    return 0;
}
