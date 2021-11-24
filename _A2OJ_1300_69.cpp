
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

   int n ;
   cin >> n;
   int _100s = 0, _200s = 0;

   for (int i = 0; i < n ; ++i) {
      int num ;
      cin >> num;
      if (num == 100)_100s++;
      if (num == 200)_200s++;
   }

   // debug(_100s);
   // debug(_200s);

   if (_100s == 0 || _200s == 0) {

      if (_100s == 0 && _200s != 0) {

         if (_200s & 1)cout << "NO" << endl;
         else cout << "YES" << endl;
      } else if (_200s == 0 && _100s != 0) {

         if (_100s & 1)cout << "NO" << endl;
         else cout << "YES" << endl;
      }
      else cout << "NO";

   } else {
      if ((_100s & 1 ) && (_200s & 1) )cout << "NO" << endl;
      else if (!(_100s & 1 ) && !(_200s & 1) )cout << "YES" << endl;
      else if (!(_100s & 1 ) && (_200s & 1))cout << "YES" << endl;
      else if ((_100s & 1 ) && !(_200s & 1))cout << "NO" << endl;

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
