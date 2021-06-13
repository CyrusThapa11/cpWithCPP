
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
#define debug(x) cout<<#x<<" "<<x<<endl;

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
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {

      int n , k ;
      cin >> n >> k;
      int arr[n];
      for (int i = 1; i <= n; ++i)
         cin >> arr[i];

      int allSameAfterk = 1;

      for (int i = k; i < n; ++i) {
         if (arr[i] != arr[i + 1]) {
            allSameAfterk = 0;
            break;
         }
      }

      if (allSameAfterk) {

         for (int i = k - 1; i >= 1; --i)
         {
            if ( arr[i] != arr[n - 1]  ) {
               cout << i  << endl;
               break;
            }
         }


      } else {
         cout << -1;
      }




   }
   return 0;

}
