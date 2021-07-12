#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
#define popcount(x) __builtin_popcount(x)
#define pb push_back()
#define all(x) x.begin(),x.end()

#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define w(x) cout << (#x) << " is " << x << "\n" ;
const char nl = '\n';


vector<int>v = {2, 4, 4, 4, 4, 1, 1, 3, 9 } ;
//1 , 1 , 2 , 3 , 4 , 4 , 9
int binsearchR(int lo, int hi, int z)
{
    int mid ;
    while(lo <= hi)
    {
        mid = hi - (hi - lo) / 2 ;
        if(z < v[mid])
        {
            return binsearchR(lo, mid - 1, z) ;
        }
        if(z > v[mid])
        {
            return binsearchR(mid + 1, hi, z) ;
        }
        if(z == v[mid])
        {
            return mid ;
        }
    }
    return -1 ;
}

int binsearch(int hi, int lo, int z)
{
    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2 ;
        if(z < v[mid])
        {
            hi = mid - 1 ;
        }
        else if(z > v[mid])
        {
            lo = mid + 1 ;
        }
        else if(z == v[mid])
        {
            return mid ;
        }
    }
    return -1 ;
}

int ternsearch(int l, int r, int z)
{
    while(l <= r)
    {
        int mid1 = l + (r - l) / 3 ;
        int mid2 = r - (r - l) / 3 ;
        if(z < v[mid1])
        {
            return ternsearch(l , mid1 - 1 , z) ;
        }
        else if(z > v[mid2])
        {
            return ternsearch(mid2 + 1 , r , z) ;
        }
        else if(z == v[mid1])
        {
            return mid1 ;
        }
        else if(z == v[mid2])
        {
            return mid2 ;
        }
    }
    return -1 ;
}


int main()
{
    int n, i, j,c, p ;
    sort(all(v)) ;
    while(cin >> p)
    {
        int a = ternsearch(v[0], v.size() -1, p) ;
        if(a != -1)
        {
            cout << p << " is at " << a << " th index\n\n" ;
        }
        else
            cout << p << " is not present in the vector\n\n" ;

    }
    return 0 ;
}
