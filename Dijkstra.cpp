#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;

#define mx 100003
#define inf 1000000000000
vector<pair<ll,ll> >edge[mx];
vector<ll>dis(mx,inf);
ll par[mx] ;

ll dijk(ll src, ll dest)
{
    ll i,j;
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > >q ;
    q.push({0,src}) ;
    dis[src] = 0;
    par[src] = -1 ;
    while(!q.empty())
    {
        ll x = q.top().second ;
        ll x_d = q.top().first ;
        q.pop() ;
        for(auto it : edge[x])
        {
            if(x_d + it.second < dis[it.first])
            {
                dis[it.first] = x_d + it.second ;
                q.push({dis[it.first],it.first});
                par[it.first] = x ;
            }
        }
    }
    if(dis[dest] == inf)
        cout << -1 << "\n" ;
    else
    {
        vector<ll>shortest;
        for(ll x =  dest ; x != -1 ; x = par[x])
        {
            shortest.push_back(x) ;
        }
        reverse(shortest.begin(),shortest.end()) ;
        for(auto it : shortest)
            cout << it << " " ;
        cout << "\n" ;
    }
}

int main()
{
    fast ;
#ifndef ONLINE_JUDGE
    freopen("input","r",stdin);
    //freopen("output.txt","w",stdout) ;
#endif
    ll i,x,y,cs,node,e ;
    cin >> node >> e ;
    for(i = 1 ; i <= e ; i++)
    {
        cin >> x >> y >> cs ;
        if(x == y)
        {
            edge[x].push_back({y,cs}) ;
        }
        else
        {
            edge[x].push_back({y,cs}) ;
            edge[y].push_back({x,cs}) ;
        }
    }
    dijk(1,node);


#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0 ;
}


/*

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1


5 8
0 3 6
2 1 1
4 2 2
2 0 3
1 4 5
1 0 1
3 2 2
4 3 1

*/
