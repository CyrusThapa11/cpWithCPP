
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


int main() {
   fast_io;    


#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif 

   ll int t = 1; 
            cin >> t;
   while       (t--){

      ll int n , sum = 0 ;
      cin>>n;
      ll int arr[n];
      
      for (ll int i = 0; i < n  ; ++i){
         cin>>arr[i];
         sum+=arr[i];
      }
      
      sort(arr,arr+n);
      ll int requiredNum = 0;

      if(sum%n != 0){
         cout<<-1<<endl;
         continue;
      }else{
         ll int equalAmt = sum/n;

         for (ll int i = 0; i < n; ++i){  
            if(arr[i] - equalAmt >= 0){
               break;
            }   else{
               requiredNum += equalAmt - arr[i];

            }
         }

         ll int j = n;
         while( j >= 0 ){

            if( requiredNum <= 0)break;  
            
            j--;
            requiredNum -= (arr[j] - equalAmt);  
            
            if( requiredNum <= 0)break;            
         }     
         if(requiredNum <= 0 ){
            cout<<n - j <<endl;
         }else{
            cout<<-1<<endl;
         }

      }




   }
   return 0;
}
