
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
   cin >> t;
   while (t--) {

      int n , m;
      cin >> n >> m;
      vector<string>vector_;
      bool canDoWithWhite = 1, canDowithBlack = 1;

      string option1 = "R", option2 = "W";

      for (int i = 1; i < m; ++i)
      {
         if (option1[i - 1] == 'R')option1[i] = 'W';
         else option1[i] = 'R';

         if (option2[i - 1] == 'R')option2[i] = 'W';
         else option2[i] = 'R';

      }

      int allAvailable = -1;

      while (n--) {
         string str1, str2;
         cin >> str1;
         str2 = str1;
         // // starting with white - 1
         // bool flipper = 1;
         // for (int i = 0; i < m; ++i)
         // {
         //    if ( (str1[i] == 'W' && flipper == 0) || (flipper == 1 && str1[i] == 'B')) {
         //       canDoWithWhite = 0;
         //       break;
         //    } else if (str1[i] == '.') {
         //       if (flipper)str1[i] = 'W';
         //       else
         //          str1[i] = 'B';
         //    }
         //    flipper = !flipper;
         // }

         if (allAvailable == -1) {
            if (str1 == )
            }




      }




   }
   return 0;
}
