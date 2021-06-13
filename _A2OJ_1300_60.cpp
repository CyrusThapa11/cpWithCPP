
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
// TLE :

using namespace std;

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

bool ansGot = 0;

int check_(char board[101][101] , int i , int j , int n , int m) {

   if ( i == 0  ) {
      if (board[i][j - 1] == 'W'  )return 0;
      else if (board[i][j - 1] == 'B'  )return 1;
   }
   else if (j == 0 ) {
      if (board[i - 1][j] == 'W'   )return 0;
      else if (board[i - 1][j ] == 'B'  )return 1;
   }
   else {
      if ((board[i][j - 1] == 'W'  ) && (board[i - 1][j] == 'W'   ))return 0;
      else if ((board[i][j - 1] == 'B'  )  && ( board[i - 1][j] == 'B'  ))return 1;
   }

   return 0;
}

void solve(char board[101][101] , int i , int j , int n , int m ) {

   if (i == n && j == 0 ) {
      bool allFilled = 1;

      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            if (board[i][j] == '.') {
               allFilled = 0;
               break;
            }
         }
      }

      if (allFilled && !ansGot)
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               cout << board[i][j];
            }
            cout << endl;
         }

      if (allFilled)ansGot = allFilled;

      return;
   }

   if ( i < 0 || j < 0 || i >= n || j >= m ) {
      return;
   }


   // if ( ( board[i - 1][j] == 'W' || board[i - 1][j] == ' - ') && ( board[i ][j - 1] == 'W' || board[i ][j - 1] == ' - ')  ) {
   //    // fill B and remove
   //    if (board[i][j] != ' - ')
   //       board[i][j] = 'B';

   //    if (j == m - 1)
   //       solve(board, i + 1, 0, n, m);
   //    else
   //       solve(board, i, j + 1, n, m);
   // } else if (  ( board[i - 1][j] == 'B' || board[i - 1][j] == ' - ') && ( board[i ][j - 1] == 'B' || board[i ][j - 1] == ' - ')) {
   //    if (board[i][j] != ' - ')
   //       board[i][j] = 'W';

   //    if (j == m - 1)
   //       solve(board, i + 1, 0, n, m);
   //    else
   //       solve(board, i, j + 1, n, m);
   // }

   if (board[i][j] == '.' || board[i][j] == '-' ) {
      if (board[i][j] == '.') {

         int white = 1;

         if (!(i == 0 && j == 0 ))
            white = check_(board , i , j , n , m);

         if (white != -1 && white == 1) {

            board[i][j] = 'W';


         }
         if (j == m - 1)
            solve(board, i + 1, 0, n, m);
         else
            solve(board, i, j + 1, n, m);


         board[i][j] = '.';
      }
      else {
         if (j == m - 1)
            solve(board, i + 1, 0, n, m);
         else
            solve(board, i, j + 1, n, m);

      }


   }

   if (board[i][j] == '.' || board[i][j] == '-' ) {

      if (board[i][j] == '.') {

         int black = 0;

         if (!(i == 0 && j == 0 ))
            black = check_(board , i , j , n , m);

         if ( black != -1 && black == 0 ) {

            board[i][j] = 'B';

            if (j == m - 1)
               solve(board, i + 1, 0, n, m);
            else
               solve(board, i, j + 1, n, m);
         }

         board[i][j] = '.';
      } else {
         if (j == m - 1)
            solve(board, i + 1, 0, n, m);
         else
            solve(board, i, j + 1, n, m);

      }
   }

   return;
}

int main() {
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {
      int n , m;
      cin >> n >> m;
      char board[101][101]  ;


      for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
            cin >> board[i][j];



      for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j) {
            if (board[i][j] != '-' && board[i][j] != 'B' && board[i][j] != 'W' ) {

               solve(board, i, j, n, m);
            }
         }




   }
   return 0;
}
