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

int knapsack(vector<int> &A, vector<int> &B, int C) {

   int siz = B.size();
   int dp[ siz + 1 ][C + 1];
   memset(dp, 0, sizeof(dp));

   for (int i = 1; i <= siz ; i++) {
      for (int j = 1; j <= C ; j++) {

         if ( B[i - 1 ] <= j ) {

            int o1 , o2;
            o1 = A[i - 1] + dp[ i - 1 ][j - B[i - 1]];
            o2 = dp[i - 1][j];
            dp[i][j] = max(o1, o2);

         } else dp[i][j] = dp[i - 1][j];
      }
   }

   return dp[siz][C];
}

int knapsackUnbounded(vector<int> &A, vector<int> &B, int C) {

   int siz = A.size();
   vector<vector<int>>dp( siz + 1, vector<int>(C + 1, 0) );

   for (int i = 1 ; i <= siz ; i++) {

      for (int j = 1 ; j <= C ; j++) {

         if ( B[i - 1] <= j ) {

            int o1, o2;
            o1 = A[i - 1] + dp[i][ j - B[i - 1]];
            o2 = dp[i - 1][j];

            dp[i][j] = max(o1, o2);
         } else dp[i][j] = dp[i - 1][j];
      }
   }


   return dp[siz][C];
}


bool isSubsetSum(int N, vector<int>&arr , int sum) {

   vector<vector<int>>dp(N + 1, vector<int>(sum + 1, 0));
   for (int i = 0; i <= N ; i++)
      dp[i][0] = 1;

   for (int i = 1; i <= N ; i++) {
      for (int j = 1; j <= sum; ++j) {

         if (arr[i - 1 ] <= j ) {

            int o1 , o2;
            o1 = dp[i - 1][j - arr[i - 1]] ;
            o2 = dp[i - 1][j];
            dp[i][j] = o1 || o2;


         } else dp[i][j] = dp[i - 1][j];
      }
   }

   return dp[N][sum] ;
}

int countOfSubset(int N, vector<int>&arr , int sum) {

   vector<vector<int>>dp(N + 1, vector<int>(sum + 1, 0));
   for (int i = 0; i <= N ; i++)
      dp[i][0] = 1;

   for (int i = 1; i <= N ; i++) {
      for (int j = 1; j <= sum; ++j) {

         if (arr[i - 1 ] <= j ) {

            int o1 , o2;
            o1 = dp[i - 1][j - arr[i - 1]] ;
            o2 = dp[i - 1][j];
            dp[i][j] = o1 + o2;

         } else dp[i][j] = dp[i - 1][j];
      }
   }

   return dp[N][sum] ;
}

bool minimumSSsumDiff(int N, vector<int>&arr ) {

   int summ = 0;
   for (int i = 0 ; i < N ; i++) {
      summ += arr[i];
   }

   if (summ % 2 != 0)return 0;

   summ /= 2;
   // int dp[N + 1][summ + 1];

   vector<vector<int>> dp (N + 1, vector<int>(summ + 1, 0));
   // memset(dp, 0, sizeof(dp));


   for (int i = 0 ; i <= N ; i++)
      dp[i][0] = 1;

   for (int i = 1 ; i <= N ; i++) {
      for (int j = 1 ; j <= summ; j++) {

         if ( arr[i - 1] <= j ) {

            int o1 = dp[i - 1][j - arr[i - 1]];
            int o2 = dp[i - 1][j];

            dp[i][j] = o1 || o2;
         } else dp[i][j] = dp[i - 1][j];

      }
   }

   return dp[N][summ];
}

int coinChange(int n, vector<int>& coins, int amount) {

   int siz = coins.size();
   // int dp[ siz + 1 ][ amount + 1];
   vector<vector<int>>dp(siz + 1, vector<int>(amount + 1, -1));
   // memset(dp, -1, sizeof(dp));

   for (int i = 0 ; i <= siz ; i++)
      dp[i][0] = 0;

   for (int i = 1 ; i <= siz ; i++) {
      for (int j = 1 ; j <= amount ; j++) {

         int currCoin = coins[i - 1];

         if (currCoin == j) {
            dp[i][j] = 1;
         } else if ( currCoin <= j ) {
            ll o1 = -1 , o2 = -1 ;

            o1 = dp[i][j - currCoin ];
            if (o1 != -1 ) o1 += 1;

            o2 = dp[i - 1][j];
            if (o1 == -1 && o2 == -1)dp[i][j] = -1;
            else if (o1 != -1 && o2 != -1)
               dp[i][j] = min(o1, o2);
            else dp[i][j] = (o1 == -1) ? o2 : o1;

         } else dp[i][j] = dp[i - 1][j];

      }
   }

   debug(dp);

   return (dp[siz][amount] == -1) ? -1 : dp[siz][amount] ;
}

int changee(int amount, vector<int>& coins) {

   int siz = coins.size();
   vector<vector<int>>dp(siz + 1, vector<int>(amount + 1, 0));


   for (int i = 0 ; i <= siz ; i++) {
      dp[i][0] = 1;
   }

   for (int i = 1 ; i <= siz ; i++) {
      for (int j = 1 ; j <= amount ; j++) {

         int currCoin = coins[i - 1];

         if (currCoin <= j) {

            int o1 , o2 ;

            o1 = dp[i ][j - currCoin] ;

            o2 = dp[i - 1][j];
            dp[i][j] = o1 + o2;

         } else dp[i][j] = dp[i - 1][j];
      }
   }

   return dp[siz][amount] ;
}

int LCS(string x, string y, int n, int m ) {

   vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

   for (int i = 1 ; i <= n ; i++) {
      for (int j = 1; j <= m ; j++) {

         if (x[i - 1] == y[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
            dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
         }
      }
   }

   return dp[n][m];
}

int LCSubstring(string x, string y, int n, int m ) {

   vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

   for (int i = 1 ; i <= n ; i++) {
      for (int j = 1; j <= m ; j++) {

         if (x[i - 1] == y[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
         } else {
            dp[i][j] = 0;
         }
      }
   }

   return dp[n][m];
}

void solve() {

   // int n, c;
   // cin >> n ;
   // cin >> c;
   // vector<int>A(n, 0) ;
   // vector<int>B ;

   // for (int i = 0; i < n ; i++) {
   //    cin >> A[i];
   // }

   // for (int i = 0; i < n ; i++) {
   //    int num;
   //    cin >> num;
   //    B.push_back(num);
   // }

   // cout<<nline << knapsack(A, B, c);
   // cout<<nline << isSubsetSum(n, A, c);
   // cout<<nline << countOfSubset(n, A, c);
   // cout<<nline << minimumSSsumDiff(n, A);

   // cout<<nline << knapsackUnbounded(A, B, c);
   // cout<<nline << coinChange(n, A, c);
   // cout<<nline << changee( c, A);

   // lcs and its variations :

   string a, b;
   cin >> a >> b;
   int n = a.length();
   int m = b.length();
   // cout << nline << LCS(a, b, n, m);
   cout << nline << LCSubstring(a, b, n, m);

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

// , keto diet , keto  , keto recipes , keto connec , keto bread , keto diet for beginners , keto meal prep  , keto diet before after , keto diet meal plan , keto pizza , keto cheesecake , keto breakfast vega , keto ice cream , keto snacks , keto meals , keto dessert , keto pancakes