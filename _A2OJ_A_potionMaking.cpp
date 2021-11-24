
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

int gcd_(int a , int b) {
   return b == 0 ? a : gcd_ (b, a % b);
}

int gcd__(int a, int b)
{
   if (b == 0)
      return a;
   return gcd__(b, a % b);

}

int main() {
   init_code();

   int t = 1;
   cin >> t;
   while (t--) {

      int n;
      cin >> n;
      int gcd = gcd__(n , 100 - n);

      cout << n / gcd + (100 - n) / gcd << endl;
   }
   return 0;
}
