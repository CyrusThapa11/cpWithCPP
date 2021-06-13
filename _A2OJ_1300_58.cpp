
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

      string hello = "hello";
      int compareWith = 0;

      string string_;
      cin >> string_;
      int len = string_.length();

      for (int i = 0; i <  len && compareWith < 5 ; ++i) {

         if ( compareWith < 5 && string_[i] == hello[compareWith]) {
            int j = i + 1;

            if (hello[compareWith ] == 'l') {


            } else {
               while (hello[compareWith] == string_[j])j++;
            }

            i = j - 1;
            compareWith++;

         }
      }
      // debug(compareWith);

      if (compareWith == 5)cout << "YES";
      else cout << "NO";

   }

   return 0;
}