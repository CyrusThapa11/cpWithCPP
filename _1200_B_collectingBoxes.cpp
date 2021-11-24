#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;

typedef                 unsigned long long ull;
typedef                 long double lld;

#define ff              first
#define ss              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define nline           "\n"
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

#define fi(a,b,step)       for( ll i = a; i < b; i+=step)
#define fj(a,b,step)       for( ll j = a; j < b; j+=step)
#define fr(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)     { cerr << t ; }
void _print(int t)    { cerr << t ; }
void _print(string t) { cerr << t ; }
void _print(char t)   { cerr << t ; }
void _print(lld t)    { cerr << t ; }
void _print(double t) { cerr << t ; }
void _print(ull t)    { cerr << t ; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//---------------------------------------------------------------------------
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

bool cmpr(pair<int, int>v1, pair<int, int>v2) {
   if (v1.ff == v2.ff)return v1.ss < v2.ss;
   return v1.ff < v2.ff;
}

void findPath(string &ans, vector<pair<int, int>> &vPair) {

   int n = vPair.size();

   int xlimit = 0 , ylimit = 0 ;

   fi(0, n, 1) {

      if (vPair[i].ff < xlimit || vPair[i].ss < ylimit ) {
         cout << "NO\n";
         return;
      }

      string r = "" , u = "";

      fj(0, vPair[i].ff - xlimit , 1)r.pb('R');
      fj(0, vPair[i].ss - ylimit , 1)u.pb('U');

      ans += (r);
      ans += (u);

      xlimit = vPair[i].ff;
      ylimit = vPair[i].ss;

   }


   cout << "YES\n" << ans << "\n" ;

   return;
}

void solve() {

   int n;
   cin >> n;
   vector<pair<int, int>>vPair;

   fi(0, n, 1) {
      int x, y;
      cin >> x >> y;
      vPair.pb({x, y});
   }

   sort(vPair.begin(), vPair.end(), cmpr);
   // debug(vPair);

   string ans = "";
   findPath(ans, vPair);


   return;
}


int main() {

   fastInput();
   ll t = 1;

   cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}