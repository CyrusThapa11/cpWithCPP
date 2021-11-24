#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//---------------------------------------------------------------------------
void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

class hashTable {
   int sizee;
   vector<int> *hashTablee;
public:

   hashTable() {

   }

   hashTable(int sizee) {
      this->sizee = (sizee  );
      hashTablee = new vector<int>[this->sizee];
      // memset(hashTablee, -1, sizeof(hashTablee));
      // hashTable =
      for (int i = 0 ; i < sizee ; i++)hashTablee[i].push_back(-1) ;
   }

   int hash(int n) {
      return n % sizee;
   }

   void insertt(int num) {

      int indexx = hash(num);
      if ( hashTablee[indexx][0]  != -1) {
         hashTablee[indexx].push_back(num);
      } else {
         hashTablee[indexx][0] = num;
      }

      cout << "inserted element " << num << " at index " << indexx << endl ;

      return;
   }

   void printTable() {
      for (int i = 0; i < sizee; ++i) {
         cout << "element at index " << i << " -> ";
         for (int j = 0; j < hashTablee[i].size() ; ++j) {
            cout << hashTablee[i][j] << ",";
         }
         cout << endl;
      }
      return;
   }
};

void solve() {

   int n;
   cin >> n;
   hashTable h1(n);
   for (int i = 0; i < n; ++i) {
      int num; cin >> num;
      h1.insertt(num);
   }
   h1.printTable();
   return;
}
int main() {
   fastInput();
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}