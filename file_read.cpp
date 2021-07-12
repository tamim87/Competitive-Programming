#include<bits/stdc++.h>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
const char nl = '\n';
const char gg = ' ' ;
template<class T> T cmax(T a, T b){return (a>b?a:b);}

#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;

void solve()
{
    
}

int main()
{
    fast ;
    int t = 1;
    // cin >> t;
    while(t--) solve();

    fstream fp; 

    fp.open("input",ios::in);   
    if(!fp)
    { 
        cout<<"No such file";
    }
    else
    {
        string s;
        while (!fp.eof()) 
        {
            fp >> s;
            cout << s << '\n' ;
        }
    }
    fp.close(); 

    return 0;
}
