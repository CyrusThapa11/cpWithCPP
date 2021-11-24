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

   int n , n2;
   cin >> n;
   vector<int>indexMarkings[n + 1];
   vector<int>numbers(n) ;


   int prevNum, num;
   cin >> prevNum;
   indexMarkings[prevNum].pb(0);
   n2 = 1;
   fi(1, n, 1) {

      cin >> num;
      if (num != prevNum) {
         n2++;
         indexMarkings[num].pb(i);
      }
      prevNum = num;
   }

   debug(n2);

   if (n2 == 1) {
      cout << "0\n";
      return;
   }

   int ans = INT_MAX;

   fi(1, n2 + 1, 1) {
      // cout << indexMarkings[i].size() << " ";

      if (indexMarkings[i].size() != 0) {
         int currAns = 0;

         if ( indexMarkings[i].size() == 1) {
            debug(i);
            debug(indexMarkings[i][0]);
            if (indexMarkings[i][0] == 0 || indexMarkings[i][0] == n2 ) currAns = 1;
            else currAns = 2;

            ans = min(ans, currAns);

         } else {

            currAns = indexMarkings[i].size();

            if (indexMarkings[i][0] == 0 && indexMarkings[i][currAns - 1] == n2 - 1 )currAns -= 1;
            else if (indexMarkings[i][0] != 0 && indexMarkings[i][0] != n2 ) {
               currAns += 1;
            }

            ans = min(ans, currAns);
         }
      }
   }
   cout << ans << nline;

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