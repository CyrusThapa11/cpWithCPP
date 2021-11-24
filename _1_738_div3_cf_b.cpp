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


void findString(string &imperfectString, string & ans, int len1, int pos , char replacement) {

   if (pos == 0) {

      if (ans[pos] == '?' ) {

         if (replacement == 'a' ) {
            ans[pos] = 'B';
            return ;
         }
         else
            ans[pos] = replacement;

      }

      return;
   }

   if (ans[pos] == '?' ) {

      if (replacement == 'a' ) {

         if (pos != 0)
            findString(imperfectString, ans, len1, pos - 1, 'a' );
         else {
            ans[pos] = 'B';
            return ;
         }


         if (ans[pos - 1] == 'R')ans[pos] = 'B';
         else ans[pos] = 'R';

         return;
      }
      else {

         ans[pos] = replacement;
         if (pos == 0)return;

         if (replacement == 'R')
            findString(imperfectString, ans, len1, pos - 1, 'B' );
         else
            findString(imperfectString, ans, len1, pos - 1, 'R' );

         return;
      }

   } else {

      if (ans[pos] == 'R')
         findString(imperfectString, ans, len1, pos - 1, 'B' );
      else findString(imperfectString, ans, len1, pos - 1, 'R' );

   }

   return;
}

void solve() {

   // int len1, len2 ;
   // cin >> len1;
   // len2 = len1;
   // string comparee1 = "" , comparee2 = "" , fillBlanks = "" ;
   // cin >> fillBlanks;
   // string ans1 = "" , ans2 = "";

   // while (len2--) {
   //    if (len2 & 1)
   //       comparee2.pb( 'B');
   //    else comparee2.pb( 'R');

   //    if (len2 & 1)
   //       comparee1.pb( 'R');
   //    else comparee1.pb( 'B');
   // }

   // len2 = len1;

   // fr(i, 0, len2, 1) {

   //    if (fillBlanks[i] != '?' ) {
   //       ans1.pb(fillBlanks[i]);
   //       ans2.pb(fillBlanks[i]);
   //    } else {
   //       ans1.pb(comparee1[i]);
   //       ans2.pb(comparee2[i]);
   //    }
   // }

   // int imperfectness1 = 0, imperfectness2 = 0;

   // fr(i, 0, len2, 1) {
   //    if (i != len2 - 1) {
   //       if (ans1[i] == ans1[i + 1] )imperfectness1++;
   //       if (ans2[i] == ans2[i + 1] )imperfectness2++;
   //    }
   // }

   // if (imperfectness2 < imperfectness1)cout << ans2 << "\n";
   // else cout << ans1 << "\n";

   int len1, len2;
   cin >> len1;
   len2 = len1;

   string imperfectString = "" ;
   cin >> imperfectString;
   string ans = imperfectString;
   findString(imperfectString, ans, len1, len1 - 1 , 'a' );
   cout << ans << "\n" ;


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