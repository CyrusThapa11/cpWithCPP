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

void solve() {

   int n , k;
   cin >> n >> k;
   int arr[n] , arr2[n];
   vector<pair<int, int>>vec_;

   fr(i, 0, n, 1) {
      cin >> arr[i];
      arr2[i] = arr[i];
      vec_.pb({arr[i], i});
   }

   sort(vec_.begin(), vec_.end());


   // int reqK = 0;
   // fr(i, 1, n, 1) {
   //    if (arr[i] >= arr[i - 1] ) {
   //    } else {
   //       reqK++;
   //    }
   // }

   // if (arr[n - 1] < arr[n - 2]) {
   //    reqK++;
   // }

   // if (reqK <= k) {
   //    cout << "Yes\n";
   // } else {
   //    cout << "No\n";
   // }

   int count = 0;

   // fr(i, 0, n, 1) {
   for (int i = 0 ; i < n ; ) {

      int currElem = vec_[i].first;
      int idx = vec_[i].second;
      int j1 = idx , j2 = i;
      for ( ; j1 < n  ; j1++ , j2++ ) {
         if ( arr[j1] == vec_[j2].first ) {

         } else break;
      }
      count++;
      i = j2;
   }

   debug(count);
   debug(k);

   if (count <= k) {
      cout << "Yes\n";
   } else {
      cout << "No\n";
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