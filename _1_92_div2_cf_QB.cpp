
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

int table[100002][6] = { -1};

int solve( int*arr ,  int i ,  int kk ,  int zz ,  int n) {

   if (i < 0 || i >= n || kk == 0 )return 0;


   if (table[i][zz] != -1)return table[i][zz];

   int val = 0;
   // cout << "hi";
   if (i < n)
      val = max(val , arr[i] + solve(arr, i + 1, kk - 1, zz , n)  );

   if (i >= 0 && zz > 0)
      val = max(val , arr[i] + solve(arr, i - 1, kk - 1, zz - 1 , n)  );


   return  table[i][zz] = val;
}


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

      int n , k , z;
      cin >> n >> k >> z;
      int arr[n];
      for (int i = 0; i < n; ++i)
         cin >> arr[i];


      // debug(arr[0]);
      memset(table, -1, sizeof(table));
      int ans = solve( arr , 1, k , z , n );
      // debug(ans);
      ans += arr[0] ;
      cout << ans << endl;

   }
   return 0;
}
