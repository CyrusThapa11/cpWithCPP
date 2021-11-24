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

void solve() {

   int n, m;
   cin >> m >> n;
   // vector < vector<int>(n + 1, vector<int>(m + 1, 0)) > arr;
   // int arr[n + 1][m + 1];

   vector<vector<int>>arr(n + 1, vector<int>(m + 1, 0));

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> arr[i][j];
      }
   }

   int freq[m + 2] ;
   memset(freq, 0, sizeof(freq));

   for (int i = 0; i < n; ++i) {

      int maxx = INT_MIN;
      for (int j = 0; j < m; ++j) {
         if (arr[i][j] > maxx ) {
            maxx = arr[i][j];
         }
      }

      debug(maxx);
      for (int j = m - 1; j >= 0 ; --j) {
         if (arr[i][j] == maxx ) {
            arr[i][m] = j;
         }
      }
      debug( arr[i][m]);
      freq[ arr[i][m] ]++;
   }
   debug(arr);
   for (auto el : freq) {
      debug(el);
   }

   int maxVotedPerson = 0;

   // debug(freq);

   for (int i = 0 ; i < m ; i++) {
      if (freq[i] != 0) {
         if (freq[i] > freq[maxVotedPerson] ) {
            maxVotedPerson = i ;
         }
      }
   }
   debug(maxVotedPerson);
   int max2Present = 0;
   set<pair<int, int>>vpair;

   for (int i = 0 ; i < n ; i++) {
      if ( freq[i] == freq[maxVotedPerson]  )  {
         int sum = 0;
         for (int j = 0 ; j < n ; j++) {
            sum += arr[j][i];
         }
         vpair.insert({i, freq[maxVotedPerson]});
      }
   }
   debug(vpair);
   if (!vpair.empty())
      cout << ((vpair.begin())->ff ) + 1 << nline;
   else cout << maxVotedPerson + 1 << nline;


   return;
}


int main() {

   fastInput();
   ll t = 1;

   // cin>>t;
   while (t--) {
      solve();
   }

   return 0;
}