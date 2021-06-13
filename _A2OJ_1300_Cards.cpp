
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

      int n ;
      cin >> n;

      int arr[n] , sum = 0;
      for (auto &i : arr) {
         cin >> i;
         sum += i;
      }

      int cumOfcards = sum / (n / 2);

      // sort(arr, arr + n);

      set<pair<int, int>> set_;

      for (int i = 0; i < n ; ++i) {

         int j = i + 1;
         int currElem = arr[i];

         for (; j < n; ++j) {
            if (arr[i] != -1 && arr[j] != -1 && arr[j] + currElem == cumOfcards) {
               set_.insert({i + 1, j + 1});
               arr[j] = -1;
               arr[i] = -1;
               break;
            }
         }
      }

      for (auto pari_ : set_) {
         cout << pari_.first << " " << pari_.second << endl;
      }




   }
   return 0;
}
