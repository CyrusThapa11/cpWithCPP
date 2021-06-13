
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

}

int main() {

   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   // init_code();
   int t = 1;
   // cin >> t;
   while (t--) {

      int n , m;
      cin >> n >> m;
      int arr[m];
      // debug(n);
      // debug(m);
      for (auto &i : arr)
         cin >> i;
      // debug(arr[0]);

      sort(arr, arr + m);

      int start = 0 ;
      int ans = INT_MAX;

      int diff = n - 1 ;
      for (int i = 0; i <= m - n; ++i) {
         // if(ans > abs())
         ans = min(ans , abs(arr[ i + diff ] - arr[i]));
      }

      cout << ans << endl;

   }

   return 0;
}