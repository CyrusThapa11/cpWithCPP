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
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

#define fi(a,b,step)   for( ll i = a; i < b; i+=step)
#define fj(a,b,step)   for( ll j = a; j < b; j+=step)
#define fr(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//-----------------------------------------------------------------------------

// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
// #define pb push_back
// #define ppb pop_back

// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

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

int freq[1000001] = {0};

void solve() {

   int n, k, d;
   cin >> n >> k >> d;
   int arr[n];

   fr(i, 0, n, 1)cin >> arr[i];

   // d--;
   // int minn = INT_MAX;
   // for (int i = 0; i + d < n; ++i) {
   //    set<int>set_;
   //    for (int j = 0 ; j <= d ; j++ ) {
   //       set_.insert(arr[i + j]);
   //    }
   //    int s = set_.size();
   //    minn = min(minn, s);
   // }

   // --------- hard version ------

   for (int i = 0 ; i < n; i++) {
      freq[arr[i]] = 0;
   }

   int mincount = 0 , minn = INT_MAX;

   for (int i = 0 ; i < d; i++) {
      if (freq[arr[i]] == 0)mincount++;
      // debug(arr[i]);
      freq[arr[i]]++;
   }
   debug(mincount);
   for (int i = 0 ; i < d; i++) {
      debug(freq[arr[i]]);
      debug(arr[i]);
   }
   debug('\n');

   minn = mincount;
   int j = d;
   for (int i = 1 ; j < n ; i++) {
      debug(arr[i]);
      debug(freq[arr[i]]);
      debug(arr[j]);
      debug(freq[arr[j]]);
      int currElem = arr[i];
      int prevElem = arr[i - 1];

      if (freq[prevElem] == 1) mincount--;
      freq[prevElem]--;

      currElem = arr[j];

      if (freq[currElem] == 0) mincount++;
      freq[currElem]++;

      debug(arr[i]);
      debug(freq[arr[i]]);
      debug(arr[j]);
      debug(freq[arr[j]]);

      minn = min(minn, mincount);
      j++;
   }

   cout << minn << "\n";

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
