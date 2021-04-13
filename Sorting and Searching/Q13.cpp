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
    deque<int>dq;
    set<int>s;

    dq.push_back(a[0]);
    int ans=1;
    s.ins(a[0]);

    for(int i=1;i<n;i++)
    {
        if(s.find(a[i])==s.end())
        {
            s.ins(a[i]);
            dq.push_back(a[i]);
            if(dq.size()>ans)ans=dq.size();
        }
        else
        {
            while(dq.size()>0 && dq.front()!=a[i])
            {
                auto itr=s.find(dq.front());
                s.erase(itr);
                dq.pop_front();
            }
            auto itr=s.find(dq.front());
            s.erase(itr);
            dq.pop_front();
           
            s.ins(a[i]);
            dq.push_back(a[i]);
            if(dq.size()>ans)ans=dq.size();
        }
    }
    if(dq.size()>ans)ans=dq.size();
    cout<<ans<<endl;
    return 0;
}