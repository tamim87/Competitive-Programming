#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;

#define mx 100000
vector<int>edge[mx];
vector<int>cost[mx];

bool vis[1001];
int dis[1001];
int p[10001];

int bfs(int src,int dest)
{
    int i,j,x;
    queue<int>q ;
    //vector<int>dis(1001,100000000);
    //dis.clear() ;
    memset(vis,0,sizeof(vis)) ;
    memset(dis,100000000,sizeof(dis)) ;
    dis[src] = 0;
    vis[src] = true;
    q.push(src) ;
    p[src] = -1;
    while(!q.empty())
    {
        x = q.front() ;
        q.pop() ;
        for(i = 0 ; i < edge[x].size() ; i++)
        {
            if(!vis[edge[x][i]])
            {
                dis[edge[x][i]] = dis[x] + 1 ;
                vis[edge[x][i]] = true;
                q.push(edge[x][i]);
                p[edge[x][i]] = x ;
            }
        }
    }
    if(vis[dest] == 0)
    {
        cout << "No path\n" ;
    }
    else
    {
        vector<int>path;
        for(x = dest ; x != -1 ; x = p[x])
        {
            path.push_back(x) ;
        }
        reverse(path.begin(), path.end()) ;
        for(auto it : path)
        {
            cout << it << " " ;
        }
        cout << "\n\n" ;
        path.clear();
    }
    return dis[dest] ;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    //freopen("output.txt","w",stdout) ;
#endif

    int t,n,i,j,k ;
    int node,e;
    cin >> node >> e ;
    for(i = 1 ; i <= e ; i++)
    {
        int x, y ;
        cin >> x >> y ;
        if(x == y)
        {
            edge[x].push_back(y) ;
            //cost[x].pb(1) ;
        }
        else
        {
            edge[x].push_back(y) ;
            edge[y].push_back(x) ;
            //cost[x].pb(1) ;
            //cost[y].pb(1) ;
        }
    }
    for(i = 0 ; i < node ; i++)
        sort(edge[i].begin(),edge[i].end()) ;
//    for(i = 0 ; i < node ; i++)
//    {
//        for(int j = 0 ; j < edge[i].size() ; j++)
//        {
//            cout << edge[i][j] << " " ;
//        }
//        cout << "\n" ;
//    }
//    cout << "\n" ;

    cout << bfs(1,6) << "\n" ;//3
//    cout << bfs(5,2) << "\n" ;//2
//    cout << bfs(5,5) << "\n" ;//0
//    cout << bfs(2,4) << "\n" ;//1
    //cout << bfs(3,1) << "\n" ;//2

}
/*

6 8
1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6

*/
