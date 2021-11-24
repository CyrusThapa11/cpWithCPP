
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
   int arr[n], freq[8] = {0} ;

   for (auto &i : arr) {
      cin >> i;
      freq[i]++;
      // cout << i << " " << freq[i] << endl;
   }
   // debug(freq[3]);

   if (freq[1] == freq[2] + freq[3] && freq[1] == freq[4] + freq[6] && freq[5] == 0 && freq[7] == 0 && freq[4] <= freq[2]  ) {

      // 124
      int start = 1;
      while ( freq[4] ) {
         cout << "1 " << "2 " << "4" << endl;
         // start++;
         freq[2]--;
         freq[4]--;
      }

      // 126
      start = 1;

      int minFreq = min(freq[2], freq[6]);

      while ( start <= minFreq ) {
         cout << "1 " << "2 " << "6" << endl;
         start++;
         freq[2]--;
         freq[6]--;
      }

      //136
      start = 1;
      while ( start <= freq[6] ) {
         cout << "1 " << "3 " << "6" << endl;
         start++;
      }

   } else {
      cout << -1 << endl;
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
