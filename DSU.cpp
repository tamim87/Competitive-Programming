#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
const int mod = 1e9+7;
const double eps = 1e-9;
const char nl = '\n';
const char gg = ' ' ;

//template <class T>
//ostream &operator <<(ostream &os, vector<T>&v){for(auto& x:v)os << x << " ";return os;}
//
//template <class a, class b>
//ostream &operator <<(ostream &os, const pair<a,b>&p){os << "(" << p.first << "," << p.second << ")";return os;}
#ifndef ONLINE_JUDGE
#define w(x) cout << (#x) << " is " << x << "\n" ;
#else
#define w(x)
#endif

#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;


vector<ll>par,siz;

struct edge
{
    ll u,v,w;
    edge() {}
    edge(ll _u, ll _v, ll _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};

bool operator<(edge a, edge b)
{
    return a.w<b.w;
}

void init(ll x)
{
    ll i;
    par.resize(x+1);
    siz.resize(x+1,1);
    for(i=0 ; i<=x ; i++)
        par[i]=i;
}

ll find(ll x)
{
    return par[x]==x ? x : par[x]=find(par[x]);
}

void uni(ll x, ll y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        if(siz[x]<siz[y])
            swap(x,y);
        par[y]=x;
        siz[x]+=siz[y];
    }
}

//struct edge
//{
//    ll u,v;
//    double w;
//    edge() {}
//    edge(ll _u, ll _v, double _w)
//    {
//        u=_u;
//        v=_v;
//        w=_w;
//    }
//};
//
//bool operator<(edge a, edge b)
//{
//    return a.w<b.w+eps;
//}


int main()
{
    fast;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,q,typ,i,j,u,v;

    cin >> n >> q;
    init(n);
    for(i=0 ; i<q ; i++)
    {
        cin >> typ >> u >> v ;
        if(typ==1)
        {
            if(find(u)!=find(v))
                uni(u,v);
        }
        else if(typ==2)
        {
            for(j=u+1 ; j<=v ; j++)
            {
                if(find(u)!=find(j))
                    uni(u,j);
            }
        }
        else
        {
            if(find(u)==find(v))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

//        cout << nl << nl;
//        for(auto i:ee)cout << i.u << gg << i.v << gg << i.w << nl;
//        cout << nl << nl ;
    return 0;
}

//1
//6 7
//1 2 5
//2 3 3
//1 4 5
//4 5 4
//5 6 4
//6 3 3
//5 2 3
//0


