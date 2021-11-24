
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
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

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

const int R = 10002, C1 = 2, C2 = 3;

bool check( ull X, ull B, ull C, ull midd, ull b_array[R][C1] , ull c_array[R][C2] )	 {

	ull c = 0, b = 0 , peopleReq = 0 , currPeople = 0;
	// debug(X);

	while (c < C && b < B) {

		if (b_array[b][0] < c_array[c][0]) {
			if (currPeople >= b_array[b][1]) {
				currPeople -= b_array[b][1];
			} else {
				peopleReq += b_array[b][1];
				// currPeople += b_array[b][1];
			}
			b++;
		} else if (C != 0) {
			if (currPeople >= c_array[c][1]) {
				currPeople += c_array[c][2];
			} else {

				if (!(b == B ))
					peopleReq += c_array[c][1] - currPeople;
				currPeople += c_array[c][1] - currPeople + c_array[c][2] ;
			}
			c++;
		}

	}

	// for (ull i = 0 ; i  < X ; i++) {
	// 	// debug(i);
	// 	if (peopleReq > midd) return 0;

	// 	if (i + 1 == b_array[b][0] ) {

	// 		// if (peopleReq )
	// 		// 	peopleReq += b_array[b][1];
	// 		if (currPeople >= b_array[b][1]) {
	// 			currPeople -= b_array[b][1];
	// 		} else {
	// 			peopleReq += b_array[b][1];
	// 			// currPeople += b_array[b][1];
	// 		}
	// 		b++;
	// 	}
	// 	if ( C != 0 && i + 1 == c_array[c][0] ) {
	// 		if (currPeople >= c_array[c][1]) {
	// 			currPeople += c_array[c][2];
	// 		} else {

	// 			if (!(b == B ))
	// 				peopleReq += c_array[c][1] - currPeople;
	// 			currPeople += c_array[c][1] - currPeople + c_array[c][2] ;
	// 		}
	// 		c++;
	// 	}
	// }

	return peopleReq <= midd;
}

void solve() {

	ull  X, B, C;
	ull b_array[10002][2] = {0} , c_array[10002][3] = {0} ;
	cin >> X >> B;

	ull maxPeople = 2e14 , maxCount = 0;

	fri(0, B, 1) {
		cin >> b_array[i][0] >> b_array[i][1] ;
		maxCount += b_array[i][1];
	}
	debug(B);

	cin >> C;
	fri(0, C, 1)cin >> c_array[i][0] >> c_array[i][1] >> c_array[i][2] ;
	// cout << maxPeople << '\n';
	ull low = 1, midd = 0 , high = maxCount , ans = 0;

	debug(C);
	while (low <= high) {

		midd = low + (high - low) / 2;

		if (check(X, B, C, midd, b_array , c_array )) {
			ans = midd;
			high = midd - 1;
		} else {
			low = midd + 1;
		}
	}

	cout << ans + 1 << '\n';
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