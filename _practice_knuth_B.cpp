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

// void init_code(){

// }

int main() {
   fast_io;


#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   int t = 1; cin >> t;
   while (t--) {

      int n ;
      cin >> n;
      int array_[n];


      for (int i = 1; i <= n; ++i)
         cin >> array_[i];
      int minIndex = 1 , maxIndex = 1;

      for (int i = 2; i <= n; ++i) {
         if (array_[i] < array_[minIndex])minIndex = i;
         if (array_[i] > array_[maxIndex])maxIndex = i;
      }

      int leftIndex_ = min(maxIndex , minIndex);
      int rightIndex_ = max(maxIndex , minIndex);

      int leftBombTimes = leftIndex_ ;
      int rightBombTimes = n - rightIndex_ + 1 ;
      int ans = 0;

      if (leftBombTimes > rightBombTimes) {
         ans += rightBombTimes;
         ans += min( leftIndex_  , rightIndex_ - leftIndex_ );
      } else {
         ans += leftBombTimes;
         ans += min( n - rightIndex_ + 1 , rightIndex_ - leftIndex_);
      }

      cout << ans << endl;


   }
   return 0;
}