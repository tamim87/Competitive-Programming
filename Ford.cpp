#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()

#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;
const char nl = '\n';

#define mx 10001
#define inf 1000000000000000000
vector<pair<ll,ll> >edge[mx];
ll dis[mx];



ll ford(ll src, ll dest)
{
    ll i,j,x;
    memset(dis,inf,sizeof(dis));
    dis[src] = 0;
    for(i = 0 ; i < dest-1 ; i++)
    {
        bool change = 0 ;
        for(x = 0 ; x < dest ; x++)
        {
            for(auto it : edge[x])
            {
                if(dis[x] + it.second < dis[it.first])
                {
                    dis[it.first] = dis[x] + it.second ;
                    change = 1 ;
                }
            }
        }
        if(!change)
            break;
    }
    for(x = 0 ; x < dest ; x++)
    {
        for(auto it : edge[x])
        {
            if(dis[x] + it.second < dis[it.first])
            {
                return -1 ;
            }
        }
    }
    return dis[dest];
}

int main()
{
    fast ;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout) ;
#endif
    ll t,i,node,e,cs,x,y;
    cin >> t ;
    while(t--)
    {
        cin >> node >> e ;
        for(i = 0 ; i < e ; i++)
        {
            cin >> x >> y >> cs ;
            edge[x].push_back({y,cs});
        }
        x = ford(1,node);
        if(x == -1)
            cout << "possible\n" ;
        else
            cout << "not possible\n" ;
        for(i = 0 ; i < mx ; i++)
        {
            edge[i].clear();
        }
    }
    return 0;
}
