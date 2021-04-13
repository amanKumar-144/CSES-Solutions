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
    int sum=0;
    map<int,int>storeFreq;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        sum+=x;

        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())storeFreq.ins(mp(x,1));
        else itr->se++;
    }
    int ans=LLONG_MAX;
    vector<int>st;
    vector<int>storeSum;
    int p=1;
    for(auto it=storeFreq.begin();it!=storeFreq.end();it++)
    {
        if(st.size()==0)
        {
            st.pb(it->se);
            storeSum.pb(it->fi*it->se);
        }
        else 
        {
            st.pb(st[p-1]+it->se);
            storeSum.pb(storeSum[p-1]+it->fi*it->se);
            p++;
        }
    }
    p=-1;
    for(auto itr=storeFreq.begin();itr!=storeFreq.end();itr++)
    {
        int element=itr->fi;
        int count=itr->se;

        int lessElementCount=0;
        int lessElementSum=0;
        if(p>=0)
        {
            lessElementCount=st[p];
            lessElementSum=storeSum[p];
        }
        int moreElementCount=n-lessElementCount-count;
        int moreElementSum=sum-element*count;
        if(p>=0)moreElementSum-=storeSum[p];
       
        
        int temp=moreElementSum-moreElementCount*element + lessElementCount*element-lessElementSum;
        //cout<<"The element and temp values are "<<element<<":::"<<temp<<endl;
        ans=min(ans,temp);
        p++;
    }
    cout<<ans<<endl;
    return 0;
}