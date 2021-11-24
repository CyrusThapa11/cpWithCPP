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

bool cmpr2( pair<int, int>&p1, pair<int, int>&p2 ) {
   if (p1.ss >= p2.ss) return 1;
   else if (p1.ff >= p1.ff)return 1;
   return 0;
}

bool cmpr1( pair<int, int>&p1, pair<int, int>&p2 ) {
   if (p1.ff > p2.ff) return 1;
   return 0;
}

void solve() {

   int n;
   cin >> n;
   // cout << n << nline;
   vector<pair<int, int>>pointCards ;
   vector<pair<int, int>>NoPointCards ;
   int n2 = n;
   while (n--) {
      int x, y;
      cin >> x >> y;
      if (y != 0) {
         NoPointCards.pb({x, y});
      } else pointCards.pb({x, y});
   }

   sort(pointCards.begin(), pointCards.end(), cmpr1);
   // reverse(pointCards.begin(), pointCards.end());
   // sort(NoPointCards.begin(), NoPointCards.end(), cmpr2);

   debug(pointCards);
   debug(NoPointCards);


   int totalCards = 1;
   int totalPoints = 0;
   for (int i = 0; i < NoPointCards.size(); ++i) {
      totalCards += NoPointCards[i].ss;
      totalCards--;
      if (totalCards == 0) {
         break;
      }
      totalPoints += NoPointCards[i].ff;
   }

   debug(totalCards);
   debug(totalPoints);
   // cout << "HI" << nline;


   for (int i = 0; i < pointCards.size(); ++i) {
      if (totalCards == 0) {
         cout << totalPoints << nline;
         return;
      }

      totalCards--;
      totalCards += pointCards[i].ss;
      totalPoints += pointCards[i].ff;
   }

   cout << totalPoints << nline;

   return;
}

int main() {

   fastInput();

   ll t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}