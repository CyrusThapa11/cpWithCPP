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
#include<list>
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

vector<string>vector_[52];
// vector<vector<int>>vector_(51, vector<string>());
unordered_map<int, int>umap;
// vector<int>mapping[51];
int arrary_[52][2];

void make_reg_string(string string_, int times, int open_ , int close_ , int num) {
   if (open_ + close_ > 2 * num || arrary_[num][1] >= num * arrary_[num][0] ) {
      return;
   }

   if (open_ + close_ == 2 * num ) {

      vector_[num].pb(string_);
      arrary_[num][1] += 1;
      debug(string_);

      return;
   }

   if (open_ == close_ && (open_ + close_ + 1 ) <= 2 * num) {

      if (open_ + 1 <= num)
         return make_reg_string(string_ + '(' , num, open_ + 1, close_ , num);

   } else if ( open_ > close_ && (open_ + close_ + 1) <= 2 * num) {

      if (open_ + 1 <= num)
         make_reg_string(string_ + '(' , num, open_ + 1, close_ , num);

      if (close_ + 1 <= num)
         make_reg_string(string_ + ')' , num, open_ , close_ + 1 , num);
      return;
   }
   return;
}

void makeRegString(string string_, int num  ) {

   int times = arrary_[num][0];
   make_reg_string(string_, times, 0, 0 , num);
   return;
}

void solve() {
   ll a, b, c, m;
   cin >> a >> b >> c >> m;


   if ( a - 1 + ( b - 1 ) + (c - 1) >= m ) {


   } else {
      // cout << "HERE" << nline;
      cout << "NO" << nline;
      return;
   }

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