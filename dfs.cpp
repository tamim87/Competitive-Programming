#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
const int mod = 1e9+7;
const double eps = 1e-9;
const char nl = '\n';
const char gg = ' ';

#define ff first
#define ss second


#define M 30005
map<int,vector<pi>>edge;
bool vis[M];
int temp,ans=-1,ep;

void dfs(int v)
{
    vis[v]=true;
    for(auto x:edge[v])
    {
        if(vis[x.ff]==0)
        {
            temp+=x.ss;
            dfs(x.ff);
            temp-=x.ss;
        }
    }
    ans=max(ans,temp);
    if(temp>=ans) ep=v;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t,n,u,v,w,i,k=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1 ; i<n ; i++)
        {
            cin >> u >> v >> w;
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
//        for(auto i:edge){cout << i.ff << ": ";for(auto j:i.ss)cout << j.ff << '(' << j.ss << ')' <<  gg ;cout << nl;}cout << nl;
        ans=-1,temp=0;
        memset(vis,0,sizeof(vis));
        dfs(0);

        temp=0;
        memset(vis,0,sizeof(vis));
        dfs(ep);

        cout << "Case " << ++k << ": " << ans << nl;
        edge.clear();
    }

    return 0;
}