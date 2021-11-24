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
#define eb              emplace_back
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
void IO() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

vector<int> add_(string n1, string n2) {

   vector<int>res;
   vector<int>ans;
   int l1, l2;
   l1 = n1.size();
   l2 = n2.size();
   vector<int>num1(l1, 0) ;
   vector<int>num2(l2, 0) ;

   reverse(n1.begin(), n1.end());
   reverse(n2.begin(), n2.end());

   for (int i = 0; i < l1 ; ++i) {
      num1[i] = n1[i] - '0';
   }
   for (int i = 0; i < l2 ; ++i) {
      num2[i] = n2[i] - '0';
   }

   // debug(num1);
   // debug(num2);

   int minL = min(l1, l2);
   int c = 0;
   int i = 0;
   // debug(minL);

   for ( ; i < minL; ++i) {
      int t = num1[i] + num2[i] + c ;
      c = t / 10;
      ans.eb( t % 10 );
   }

   int s = n1.size();

   if (s > minL) {
      for ( ; i < s; ++i) {
         int t = num1[i] + c ;
         c = t / 10;
         ans.eb( t % 10 );
      }
   }

   s = n2.size();
   if (s > minL) {

      for ( ; i < s; ++i) {
         int t = num2[i] + c ;
         c = t / 10;
         ans.eb( t % 10 );
      }
   }
   if (c) {
      while (c) {
         // int t =  c ;
         ans.eb( c % 10 );
         c = c / 10;
      }
   }
   debug(ans);
   i = 0;
   s = ans.size();
   debug(i);
   for ( ; i < s ; ++i) {
      res.eb(ans[i]);
   }

   reverse(ans.begin(), ans.end());

   return ans;
}

void solve() {


   string n1, n2;
   cin >> n1 >> n2;

   vector<int>v;
   v = add_(n1, n2);
   debug(v);


   return;
}

int main() {

   IO();

   ll t = 1;
   cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}