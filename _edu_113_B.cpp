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

// bool hogya = 0;

bool solve2(char chessBoard[52][52] , int i , int  j , string score , int n  ) {

   if ( i == n && j == 1) {

      bool ans = 0;
      for (int i = 1 ; i <= n ; i++) {

         char cheeker = score[i - 1];
         for (int j = 1; j <= n; ++j) {
            if (chessBoard[i][j] == '0')return 0;

            if ( cheeker == '1'  ) {
               if (chessBoard[i][j] == '-' )return 0;
               else ans = 1;
            } else {
               if (chessBoard[i][j] == '+') {
                  ans = 1;
                  break;
               } else return 0;
            }

         }
      }

      if (ans  ) {
         cout << "YES\n";
         for (int i = 1 ; i <= n ; i++) {
            for (int j = 1; j <= n; ++j) {
               cout << chessBoard[i][j] << " ";
            }
            cout << endl;
         }
      }
      return 0;
   }

   if (i < 1 || j < 1 || j > n || i > n) {
      return 0;
   }

   if (chessBoard[i][j] != '0' ) {
      if (j == n )
         return solve2( chessBoard , i + 1 , 1 , score , n );
      else return solve2( chessBoard , i  , j + 1 , score , n );
   }

   bool o1 = 0, o2 = 0 , o3 = 0 , o4 = 0;

   if ( score[i - 1] == '2' ) {
      chessBoard[j][i] = '-';
      chessBoard[i][j] = '+';
      o1 = (j == n) ? solve2(chessBoard, i + 1, 1, score, n  ) : solve2(chessBoard, i, j + 1, score, n  );
      if (o1) return 1;

      if (!o1) {
         chessBoard[j][i] = '+';
         chessBoard[i][j] = '-';
         o2 = (j == n) ? solve2(chessBoard, i + 1, 1, score, n  ) : solve2(chessBoard, i, j + 1, score, n  );
         if (o2)return 1;
      }

   }


   if ( (!o1) || (!o2)) {

      if ( score[i - 1] == '1' ) {
         chessBoard[j][i] = '=';
         chessBoard[i][j] = '=';
         o2 = (j == n) ? solve2(chessBoard, i + 1, 1, score, n ) : solve2(chessBoard, i, j + 1, score, n );
         if (o2)return 1;

         if (!o2) {
            chessBoard[j][i] = '-';
            chessBoard[i][j] = '+';
            o4 = (j == n) ? solve2(chessBoard, i + 1, 1, score, n ) : solve2(chessBoard, i, j + 1, score, n );
            if (o4)return 1;
         }
      }

   }

   chessBoard[i][j] = '0';

   return 0;
}


void solve() {

   int n;
   cin >> n;
   string score;
   cin >> score;
   char chessBoard[52][52];
   bool hogya = 0;

   fr(i, 1, n + 1, 1) {
      fr(j, 1, n + 1, 1) {
         if (i == j)chessBoard[i][j] = 'X';
         else chessBoard[i][j] = '0';
      }
   }

   fr(i, 1, n + 1, 1) {
      fr(j, 1, n + 1, 1) {
         if (chessBoard[i][j] == '0' ) {
            if (!hogya)
               hogya = solve2( chessBoard , i , j , score , n);
            if (hogya)break;
         }
         if (hogya)break;
      }
   }

   if (!hogya) {
      cout << "NO" << nline;
      return;
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