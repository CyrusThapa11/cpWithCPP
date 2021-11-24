#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}


void insertInOrder( int i, int position, int* arr , stack<int> &stack_ ) {
   int currNo = arr[i];

   if ( i == 0) {
      cout << " elements after rearranging are :" << endl;
      while (!stack_.empty()) {
         cout << stack_.top() << " ";
         stack_.pop();
      }
      return;
   }

   stack<int>stack_2;
   // inserting all elements except the currNO insto stack2
   while (stack_.size() != position) {
      if (stack_.top() != currNo)
         stack_2.push(stack_.top());
      stack_.pop();
   }

   // inserting the curr element into its correct position
   stack_.push(currNo);
   // reinserting the previous numbers into the stack 1
   while (!stack_2.empty()) {
      stack_.push(stack_2.top());
      stack_2.pop();
   }

   return insertInOrder(i - 1, position + 1, arr, stack_);
}

void solve() {

   int n;
   cin >> n;
   stack<int>stack_;

   int arr[n];
   int number = n;
   for (int i = 0; i < number; ++i) {
      int num;
      cin >> num;
      stack_.push(num);
   }

   for (int i = 0; i < number; ++i) {
      cin >> arr[i];
   }

   stack<int>stack_2;
   int i = n - 1 ;
   int position = 0;
   insertInOrder( i , position, arr , stack_ );

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