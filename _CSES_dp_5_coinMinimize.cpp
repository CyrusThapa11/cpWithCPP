
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

typedef                 unsigned long long int ull;
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


#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frvar(var,a,b,step)   for( ll var = a; var < b; var+=step)

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

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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


ll dp[101][1000001];

void solve() {

	ll x, n;
	cin >> n >> x;
	ll coins[n + 1];

	frvar(coin, 1, n + 1, 1)cin >> coins[coin];

	// ll dp[x + 1] ;
	// frvar(i, 0, x + 1, 1)dp[i] = INT_MAX;
	// dp[0] = 0;

	// frvar(target, 0, x + 1, 1) {
	// 	// ll minCoins = INT_MAX;
	// 	frvar(coin, 1, n + 1, 1) {
	// 		// debug(coins[coin]);
	// 		if (target == 0)   dp[target] = 0;
	// 		else if (target == coins[coin])  dp[target] = 1;
	// 		else {

	// 			if (target >= coins[coin]) {
	// 				dp[target] = min(dp[target] , 1 + dp[target - coins[coin]]);
	// 			}
	// 		}
	// 	}
	// }
	// if (dp[x] == INT_MAX)cout << -1 << '\n';
	// else
	// 	cout << dp[x] << '\n';


	frvar(i, 0, n + 1, 1)
	frvar(j, 0, x + 1, 1)
	dp[i][j] = INT_MAX;

	frvar(i, 1, n + 1, 1) {
		ll currCoin = coins[i];

		frvar(target, 0, x + 1, 1) {

			if (target == 0) dp[i][target] = 0;
			else if (currCoin == target) dp[i][target] = 1;
			else {

				ll op1, op2;
				// not include :
				op1 = dp[i - 1][target];
				// inlude :
				op2 = target >= currCoin ? 1 + dp[i][target - currCoin] : INT_MAX;
				dp[i][target] = min(op1, op2);
			}
		}
	}
	if (dp[n][x] == INT_MAX)cout << -1;
	else
		cout << dp[n][x];

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