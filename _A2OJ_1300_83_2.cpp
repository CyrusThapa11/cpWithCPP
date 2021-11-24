
#include<bits/stdc++.h>
using namespace std;

#define debug(x)        cout<<#x<<" "<<x<<endl;
#define outel()         cout<<endl;
#define fri(a,b,step)   for( int i = a; i < b; i+=step)
#define frj(a,b,step)   for( int j = a; j < b; j+=step)
#define frk(a,b,step)   for( int k = a; k < b; k+=step)

void solve() {

   int n;
   cin >> n;
   vector <vector<int>>position_( 5002 , vector<int>() ) ;

   // cout << position_.size() << endl;
   // cout << position_[0].size() << endl;

   int len = 2 * n;
   fri(0, len, 1) {
      int num;
      cin >> num;
      position_[num].push_back(i + 1);
   }

   fri(0, 5002, 1) {
      if (position_[i].size() == 1 && position_[i][0] != 0) {
         cout << -1;
         return;
      }
   }

   fri(0, 5002, 1) {
      frj(0, position_[ i ].size() , 2) {

         if (position_[ i ][j] >= 1 ) {
            cout << position_[i][j] << " " << position_[i][j + 1] ;
            outel();
            position_[i][j] = 0;
         }
      }
   }
   return;
}


int main() {

   // fastInput();
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   // cout << "Hi";
   int t = 1;
   // cin>>t;
   while (t--) {
      solve();
   }

   return 0;
}
