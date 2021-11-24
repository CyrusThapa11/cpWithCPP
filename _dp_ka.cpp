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

void ccomb1() {

   int n, x;
   cin >> n;
   int coins[n];
   for (int i = 0; i < n; ++i)
      cin >> coins[i];
   cin >> x;

   // int dp1[n + 1][x + 1];
   vector<vector<int>>dp1(n, vector<int>(x + 1, 0)) ;
   for (int i = 0; i < n; ++i) {
      for (int sum = 0; sum <= x; ++sum) {


         if (sum == 0) {
            dp1[i][sum] = 1;
         } else {
            int o1 = 0, o2 = 0;
            // include
            o1 = (coins[i] > sum ) ? 0 : dp1[ i ][ sum - coins[i] ] ;
            // exclude
            if (i != 0)o2 = dp1[i - 1][sum];

            dp1[i][sum] = o1 + o2;
         }
      }
   }

   cout << dp1[n - 1][x] << nline ;

   return;
}

int ccr1( int n, int sum, int *c, int coin ) {

   if (coin == n || sum <= 0 ) {
      if (sum == 0)return 1;
      return 0 ;
   }

   int o1 = 0, o2 = 0;

   // include
   if (c[coin] <= sum ) {
      // cant include
      o1 = ccr1(n, sum - c[coin] , c, coin );
   }

   // exclude
   o2 = ccr1( n , sum, c, coin + 1 );

   return o1 + o2 ;
}

void ccomb1Recc() {

   int n, x;
   cin >> n;
   int coins[n];
   for (int i = 0; i < n; ++i)
      cin >> coins[i];
   cin >> x;


   cout << ccr1( n , x, coins, 0 ) << nline ;

   return;
}

void cperm2() {

   int n, x;
   cin >> n;
   int coins[n];
   for (int i = 0; i < n; ++i)
      cin >> coins[i];
   cin >> x;

   vector<vector<int>>dp1(n, vector<int>(x + 1, 0));

   return;
}

void removeDigits() {
   int n;
   cin >> n;
   // int dp[n + 1];
   vector<int>v(n + 1, 0);
   v[0] = 0;
   for (int i = 1 ; i <= n; ++i) {

      int minNo = i;
      int minStep = 1e6 + 3;
      while (minNo > 0) {
         int di = minNo % 10;
         minNo /= 10;
         if (di != 0)
            minStep = min(minStep , 1 + (v[i - di]) ) ;
      }
      v[i] = minStep;
   }

   cout << v[n];
   return;
}

void bookShop() {
   int n , x;
   cin >> n >> x;
   int pages[n + 1], price[n + 1];
   int dp[n + 1][x + 1] ;

   for (int i = 0; i < n ; ++i) {
      cin >> price[i];
   }
   for (int i = 0; i < n ; ++i) {
      cin >> pages[i];
   }

   // dp[0] = 0;
   memset(dp, 0, sizeof(dp));

   for (int i = 1; i <= n ; ++i) {

      for (int paisa = 0; paisa <= x; ++paisa) {
         if (paisa == 0) {
            dp[i][paisa] = 0;
         } else {
            int o1 = 0, o2 = 0;

            // take the curr book;
            if (paisa >= price[i - 1])
               o1 = pages[i - 1] + dp[i - 1][ paisa - price[i - 1] ];
            o2 = dp[i - 1][paisa];
            dp[i][paisa ] = max(o2, o1);
         }
      }
   }
   cout << dp[ n ][ x ];

   return;
}

void coinCombination1() {
   int n, x;
   cin >> n >> x;
   int coins[n];
   // int dp[x + 1][n + 1] ;
   vector<vector<int>>dp (x + 1, vector<int>(n + 1, 0));
   for (int i = 0; i < n ; ++i) {
      cin >> coins[i];
   }

   for (int i = 0; i <= x; ++i) {
      for (int j = 0; j < n; ++j) {

         if ( i == 0)dp[i][j] = 1;
         if (coins[j] == i  )dp[i][j] += 1;
         if ( i >= coins[j] ) {
            dp[i][ j ] += dp[i - coins[j]][j];
         }
      }
   }

   debug(dp);
   cout << dp[x][n - 1];
   return;
}

void solve() {

   // ccomb1Recc();
   // removeDigits();
   // bookShop();
   coinCombination1();


   return;
}

int main() {

   IO();

   ll t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}