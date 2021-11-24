
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

#define debug(x)        cout<<#x<<" "<<x<<endl;
#define outel()         cout<<endl;
#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

void solve() {

   int n , m;
   cin >> n >> m;
   char board[n][m + 1];

   fri(0, n, 1) {
      frj(0, m, 1) {
         cin >> board[i][j];
      }
   }

   fri(0, m, 1) {

      int maxx = -1;
      // debug(maxx);
      frj(0, n, 1) {
         // board[j][i];
         if (board[j][i] - '0' > maxx ) {
            maxx = board[j][i] - '0' ;
         }
         // debug(board[j][i]);
      }

      // debug(maxx);
      // debug(i);
      // debug(j);

      frj(0, n, 1) {
         // board[j][i];
         if (board[j][i] - '0' == maxx ) {
            board[j][m] = '1' ;
         }
      }
   }
   int cnt =  0;
   fri(0, n, 1) {
      if (board[i][m] == '1')cnt++;
   }
   cout << cnt;
   outel();

   return;
}


int32_t main() {

   fastInput();

   int t = 1;
   // cin>>t;
   while (t--) {
      solve();
   }

   return 0;
}
