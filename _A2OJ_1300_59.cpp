
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
      int noOfPassengers, noOfPlanes ;
      cin >> noOfPassengers >> noOfPlanes;

      int arr[noOfPlanes ] , totalSeats = 0 ;
      for (auto &i : arr)
         cin >> i;

      for (auto &i : arr)
         totalSeats += i;
      int ans = 0;

      if (noOfPassengers == totalSeats ) {

         for (auto &i : arr) {
            ans += (i * (i + 1) ) / 2;
         }
         cout << ans << " " << ans << endl;

      } else {

         int minn = 0, maxx = 0;
         sort(arr, arr + noOfPlanes);
         int noOfPassengers2 = noOfPassengers;
         // debug(totalSeats);
         for (auto &i : arr) {
            if (noOfPassengers >= i) {
               noOfPassengers -= i;
               minn += (i * (i + 1) ) / 2;
               // cout << (i * (i + 1) ) / 2 << " " << noOfPassengers << endl;
            } else {
               int requiredSeats = i - noOfPassengers;
               noOfPassengers -= noOfPassengers;
               minn += (i * (i + 1) ) / 2 -  (requiredSeats * (requiredSeats + 1)) / 2 ;
            }
         }

         reverse(arr, arr + noOfPlanes);
         // cout << arr[0] << endl;
         int allBooked = 0;
         // while (noOfPassengers2 > 0) {

         //    for ( int i = 0 ; i < noOfPlanes ; i++ ) {
         //       if (arr[i] > 0 && noOfPassengers2 > 0 ) {
         //          maxx += arr[i];
         //          arr[i]--;
         //          noOfPassengers2--;
         //       }
         //       if (noOfPassengers2 <= 0) {
         //          allBooked = 1;
         //          break;
         //       }
         //    }
         // }

         while (noOfPassengers2 > 0) {

            noOfPassengers2--;

            // find maximum :

            for (int i = 0; i < noOfPlanes ; ++i) {
               if ( i < noOfPlanes - 1 &&  arr[i] > arr[i + 1]) {
                  maxx += arr[i];
                  arr[i]--;
                  break;
               } else if (i == noOfPlanes - 1) {
                  maxx += arr[i];
                  arr[i]--;
                  break;
               }
            }
         }


         cout << maxx << " " << minn;

      }
      return 0;
   }
}