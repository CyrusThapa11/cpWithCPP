
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

   ll int n, window;
   cin >> n >> window;
   ll int arr[n];
   ll int cumlSum[n] , j = 0 , ans = 0 , ttlSum = 0;

   for (auto &i : arr) {
      cin >> i;
   }

   // ans = cumlSum[window - 1];
   // ll int end = window;
   // // debug(ans);
   // ll int index = 0;
   // for (ll int start = 1 ; end < n ; ++start , ++end )
   // {
   //    if (ans > cumlSum[end] - cumlSum[start - 1] ) {
   //       ans = cumlSum[end] - cumlSum[start - 1] ;
   //       // debug(index);
   //       index = start + 1;
   //    }
   // }
   // if (index == 0)
   //    index = 1;

   // cout << index;

   ll int index = 0;
   for (ll int i = 0; i < window; ++i) {
      ttlSum += arr[i];
   }
   ans = ttlSum;
   for (ll int i = 1 ; window + i - 1 < n; ++i)
   {
      ttlSum = ttlSum - arr[i - 1] + arr[window + i - 1];
      if (ttlSum < ans ) {
         ans = ttlSum;
         index = i;
      }
   }

   if (index == 0)index = 1;
   else index += 1;

   cout << index;

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
