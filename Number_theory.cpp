//"Whether you think you can, or you think you can't--you're right." --Henry Ford
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
const int mod = 1e9+7;
const char nl = '\n';

template <class T>
ostream &operator <<(ostream &os, const vector<T>&v)
{
    for(auto& x:v)os << x << " ";
    return os;
}

template <class a, class b>
ostream &operator <<(ostream &os, const pair<a,b>&p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

#define PI acos(-1)
#define all(v) v.begin() , v.end()
#define pb push_back
#define ff first
#define ss second
#define eps 1e-9
#define w(x) cout << (#x) << " is " << x << "\n" ;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;

int ceil2(int a, int b)
{
    if(a==0) return 0;
    return (a-1)/b + 1;
}

const int M = 1e5+5;
bool mark[M] ;
vector<int>prime;
void sieve()
{
    int i , j , n ;
    for(i=3 ; i*i <= M ; i+=2)
    {
        if(!mark[i])
        {
            for(j = i*i ; j < M ; j+=i+i)
                mark[j] = true ;
        }
    }
    prime.push_back(2) ;
    // cin >> n;
    n = 100000;
    for(i=3 ; i <= n ; i+=2)
    {
        if(!mark[i])
            prime.push_back(i) ;
    }
}

map<ll,ll> factorize(ll n)
{
    map<ll,ll>fact;
    ll cnt=0,i;
    for(i=0 ; i<prime.size() && prime[i]*prime[i]<=n ; i++)
    {
        cnt=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            fact[prime[i]]=cnt;
        }
    }
    if(n>1)fact[n]=1;
    return fact;
}

ll nod(ll n)
{
    ll i,c;
    ll div =1 ;
    for(i=0 ; i<prime.size() && prime[i]*prime[i] <= n ; i++)
    {
        c=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
        }
        c++;
        div*=c;
    }
    if(n>1)
        div*=2;
    return div;
}

ll sod(ll n)
{
    ll i,c,tsum,divsum=1;
    for(i=0 ; i<prime.size() && prime[i]*prime[i] <= n ; i++)
    {
        if(n%prime[i]==0)
        {
            c=1;
            tsum=1;
            while(n%prime[i]==0)
            {
                c*=prime[i];
                tsum+=c;
                n/=prime[i];
            }
            divsum*=tsum;
        }
    }
    if(n>1)
        divsum*=(n+1);
    return divsum;
}

// ll bigmod(ll b, ll p, ll m)
// {
//     if(p == 0)
//         return 1 ;
//     ll x = bigmod(b,p/2,m)%m ;
//     if(p & 1)
//         return (b * x * x)%m ;
//     else
//         return (x * x)%m ;
// }

ll bigmod(ll b , ll p , ll m)
{
    if(p == 0) return 1 ;

    ll x = bigmod(b, p/2, m);
    x = (x % m * x % m) % m;
    if(p&1)
        return (x % m * b % m) % m;
    return x;
}

int gcd(int a, int b)
{
    if(a == 0)
        return b ;
    return gcd(b%a,a) ;
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int b2d(long long n)
{
    int decimal=0, i=0, rem;
    while(n!=0)
    {
        rem=n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}

vector<ll> d2b(int n)
{
    vector<ll> binary(12);
    while(n>0)
    {
        binary.pb( n % 2);
        n = n / 2;
    }
    reverse(all(binary));
    return binary;
}

// int bigmod(int base , int power , int mod)
// {
//    if(power == 0) return 1 ;
//    else if(power % 2 == 0)
//    {
//        int p1 = bigmod(base , power / 2 , mod) % mod ;
//        return (p1 * p1) % mod ;
//    }
//    else
//    {
//        int p1 = base % mod ;
//        int p2 = bigmod(base , power-1 , mod) % mod ;
//        return (p1 * p2) % mod ;
//    }
// }

//void sieve()
//{
//    ll i , j ;
//    for(i = 2 ; i < mx ; i+=2)
//        if(i > 2) mark[i] = true ;
//    prime.pb(2) ;
//    for(i = 3 ; i * i <= mx ; i+=2)
//    {
//        if(mark[i] != 1)
//        {
//            for(j = i * i ; j < mx ; j = j + i + i)
//                mark[j] = true ;
//        }
//    }
//    for(i = 3 ; i < mx ; i+=2)
//    {
//        if(mark[i] != 1)
//            prime.pb(i) ;
//    }
//}

int countdiv(int m)
{
    int div = 1 ;
    int i, cnt ;
    for(i = 0 ; i < prime.size() && prime[i] * prime[i] <= m ; i++)
    {
        if(m % prime[i] == 0)
        {
            cnt = 1 ;
            while(m % prime[i] == 0)
            {
                m /= prime[i] ;
                cnt++ ;
            }
            div *= cnt ;
        }
    }
    if(m>1)
        div*=2;
    return div ;
}

int divcount(int m) //naive approach
{
    int i,div = 0 ;
    for(i = 1 ; i * i <= m ; i++)
    {
        if(i * i == m)
        {
            div++ ;
        }
        else if(m % i == 0)
        {
            div+=2 ;
        }
    }
    return div ;
}

int main()
{
    fast ;
#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

    sieve() ;
    ll x ;
//    while(cin >> x)
//    {
//        factorise(x) ;
//        for(auto it:factor)
//        {
//            cout << it << " " ;
//        }
//        factor.clear() ;
//        cout << "\n" ;
//    }
    cin >> x ;
    ll y = nod(x);
    cout << y << "\n";

}
