
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define debug(x) c-out<<#x<<" "<<x<<endl;


//----------------------------------------------------------------------------------


using namespace std;

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int main() {

// n = 5
//           0
//         0 1 0
//       0 1 2 1 0
//     0 1 2 3 2 1 0
//   0 1 2 3 4 3 2 1 0
// 0 1 2 3 4 5 4 3 2 1 0
//   0 1 2 3 4 3 2 1 0
//     0 1 2 3 2 1 0
//       0 1 2 1 0
//         0 1 0
//           0


   init_code();
   int t = 1;
   while (t--) {
      int n ;
      cin >> n;
      int spacees = 2 * n ;
      for (int i = 0; i <= n; ++i) {


         for (int j = 0; j < spacees; ++j)
            cout << " ";

         for (int j = 0; j <= i; ++j) {
            // if (j != i)
            if (i != 0)
               cout << j << " ";
            else
               cout << j;
         }

         for (int j = i - 1; j >= 0; --j) {
            if (j != 0)
               cout << j << " ";
            else
               cout << j;
         }

         spacees -= 2;

         cout << endl;
      }

      spacees += 4;

      for (int i = n - 1; i >= 0; --i) {


         for (int j = 0; j < spacees; ++j)
            cout << " ";

         for (int j = 0; j <= i; ++j) {
            if ( i != 0)
               cout << j << " ";
            else
               cout << j;
         }

         for (int j = i - 1; j >= 0; --j) {
            if (j != 0)
               cout << j << " ";
            else
               cout << j;
         }

         spacees += 2;

         cout << endl;
      }


   }
   return 0;
}
