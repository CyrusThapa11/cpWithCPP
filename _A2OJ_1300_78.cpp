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

void solve() {

   ll int y , k , n;
   cin >> y >> k >> n;

   if ( y >= n ) {
      cout << "-1" << endl;
      return;
   } else {

      ll int sum = 0;
      int firstMultiple = y % k ;
      int count = 0;
      firstMultiple = y + k - firstMultiple;

      for (int i = firstMultiple ; i <= n ; i += k)
      {
         count++;
         cout << i - y << " ";
      }
      if (count == 0)
         cout << "-1";
      return;

   }
   return;
}


int main() {
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
