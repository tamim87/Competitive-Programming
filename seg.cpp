#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(v) v.begin() , v.end()

#define mx 100001
int ar[mx] ;
int tree[mx * 3] ;
vector<int>v ;
void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = ar[b] ;
        return ;
    }
    int left = node * 2 ;
    int right = (node * 2) + 1 ;
    int mid = (b + e) / 2 ;
    build(left, b, mid) ;
    build(right, mid + 1, e) ;
    tree[node] = tree[left] + tree[right] ;
}

int query(int node, int b, int e, int i, int j)
{
    if(e < i || b > j)
    {
        return -100000000;
    }
    if(b >= i && e <= j)
    {
        return tree[node] ;
        v.pb(tree[node]) ;
    }
    int left = node * 2 ;
    int right = (node * 2 ) + 1  ;
    int mid = (b + e) / 2 ;
    int p1 = query(left, b, mid, i, j) ;
    int p2 = query(right, mid + 1, e, i, j) ;
    //return max(p1 , p2) ;
    sort(all(v)) ;
    return (v[v.size()-1] + v[v.size()-2]) ;
}

void update(int node, int b, int e, int i, int val)
{
    if(e < i || b > i)
    {
        return ;
    }
    if(b >= i && e <= i)
    {
        tree[node] = val ;
        return ;
    }
    int left = node * 2 ;
    int right = left + 1 ;
    int mid = ( b + e ) / 2 ;
    update(left, b, mid, i, val) ;
    update(right, mid + 1, e, i, val) ;
    tree[node] = tree[left] + tree[right] ;
}

int main()
{
    int t, n, m, i,j, c, x, y, v;
    char s[100] ;
    //scanf("%d",&t) ;

        scanf("%d",&n) ;
        //memset(ar , 0 , sizeof(ar)) ;
        //memset(tree , 0 , sizeof(tree)) ;
        for(j = 1 ; j <= n ; j++)
        {
            scanf("%d",&ar[j]) ;
        }
        build(1, 1, n) ;
        scanf("%d",&m) ;
        while(m--)
        {
            getchar() ;
            scanf("%s",s) ;
            scanf("%d %d",&x , &y) ;
            if(s[0] == 'U')
            {
                update(1, 1, n, x, y) ;
            }
            else if(s[0] == 'Q')
            {
                printf("%d\n", query(1, 1, n, x , y) ) ;
            }
        }

    return 0;
}
