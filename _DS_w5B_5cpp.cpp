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
   int *hashTablee;
public:
   hashTable(int sizee) {
      this->sizee = 11;
      hashTablee = new int[this->sizee];
      for (int i = 0 ; i < this->sizee ; i++)hashTablee[i] = -1;
   }

   int hash(int n) {
      return n % 11;
   }

   void insertt(int num) {

      int indexx = hash(num);
      if ( hashTablee[indexx]  != -1) {

         for (int i = 1; i < sizee ; ++i) {
            int idx = hash(num) ;
            idx = (idx + i * i) % sizee;
            if (idx == indexx) {
               cout << "table is full cant insertt more elements " << endl;
               return;
            } else if (hashTablee[idx] == -1) {
               hashTablee[idx] = num;

               cout << "inserted element " << num << " at index " << idx << endl    ;
               break;
            }
         }
      } else {
         hashTablee[indexx] = num;
         cout << "inserted element " << num << " at index " << indexx << endl ;
      }
   }

   void printTable() {
      for (int i = 0; i < sizee; ++i) {
         cout << "element at index " << i << " -> " << hashTablee[i] << endl;
      }
      return;
   }
};

void solve() {
   hashTable h1(11);
   h1.insertt(50);
   h1.insertt(700);
   h1.insertt(76);
   h1.insertt(85);
   h1.insertt(92);
   h1.insertt(73);
   h1.insertt(101);
   h1.insertt(70);
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