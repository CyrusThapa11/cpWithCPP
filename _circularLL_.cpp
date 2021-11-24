#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fastInput() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}

template<typename t>
class node {
public:
   t data;
   node<t> *next;
   node(t data) {
      this->data = data;
      next = NULL;
   }
};

template<typename T>
class SingleNode {
public:
   T data;
   SingleNode<T> *next;
   SingleNode(T d) {
      data = d;
      next = NULL;
   }
};

template<typename T>
void insertAtHead( SingleNode<T>*&root, T d ) {
   if (root == NULL) {
      root = new SingleNode<T>(d);
      return;
   }

   SingleNode<T>*temp = new SingleNode<T>(d);

   temp->next = root;
   root = temp;

   return;
}

template<typename T>
void printLL(SingleNode<T>* root) {
   SingleNode<T>*temp = root;
   while (temp->next != NULL) {
      cout << temp->data << " " ;
      temp = temp -> next;
   }
   cout << temp->data << " ";
   cout << endl;
   return;
}

template<typename t>
void inserAtHead(node<t>*&head , t data) {

   if (head == NULL) {
      head = new node<t>(data);
      head ->next = head;
      return;
   }

   node<t>*temp = head;
   while (temp->next != head) {
      temp = temp->next;
   }

   temp->next = new node<t>(data);
   temp->next->next = head;

   // cout << head->data << " ";

   return;
}

template<typename t>
void moveLastToFront( SingleNode<t>*& head_) {
   SingleNode<t>*temp = head_;
   SingleNode<t>*lastNode = head_;

   while (temp->next->next != NULL) {
      temp = temp->next;
   }

   lastNode = temp->next;
   temp->next = NULL;
   lastNode->next = head_;
   head_ = lastNode;
   return;
}


template<typename t>
void printCircularLL(node<t>*head) {
   node<t>*temp = head;
   while (temp->next != head) {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << temp->data << " \n";

   return;
}

template<typename t>
void deleteNode(node<t>*& head, t delNode) {

   if (head->data == delNode) {
      node<t>*temp = head;
      temp = temp->next;
      head->next = NULL;
      delete(head);
      head = temp;
      return;
   }

   node<t>*temp = head;

   while (temp->next->data != delNode && temp->next != head) {
      // cout << temp->data << " ";
      temp = temp->next;
   }

   if (temp->next == head) {
      cout << " not found tthe element \n";
      return;
   }

   node<t>*nextPtr = temp->next->next;
   delete(temp->next);
   temp->next = nextPtr;

   return;
}

template<typename t>
void concatinateCircularLL(node<t>*&head1, node<t>*&head2) {

   node<t>*headPointer1 = head1;
   node<t>*headPointer2 = head2;
   node<t>*tailPointer1 = NULL;
   node<t>*tailPointer2 = NULL;


   while (headPointer1->next != head1) {
      headPointer1 = headPointer1->next;
   }
   headPointer1->next = head2;

   while (headPointer2->next != head2) {
      headPointer2 = headPointer2->next;
   }
   headPointer2->next = head1;

   return;
}

template<typename t>
void removeDuplicates(node<t>*& head) {
   unordered_map<int, int>mapping_;

   node<t>*temp = head;
   while (temp->next != head) {
      mapping_[temp->data]++;
      temp = temp->next;
   }

   mapping_[temp->data]++;
   temp = head;

   while (temp->next != head) {

      if (mapping_[temp->next->data] > 1) {

         node<t>*temp3 = temp->next;

         temp->next = temp3->next;
         mapping_[temp3->data]--;
         delete(temp3);
      }

      temp = temp->next;
   }

   return;
}

template<typename t>
int getLent( node<t>* head ) {

   int cnt =  1;
   node<t>*temp = head;
   while (temp->next != head) {
      temp = temp->next;
      cnt++;
   }
   return cnt;
}

template<typename t>
node<t>* splitCircularLL(node<t>*& head3) {

   int len = getLent(head3);

   node<t>*temp1 = head3;
   node<t>*temp2 = head3;

   int count = 1;

   while ( count < len / 2 ) {
      temp1 = temp1->next;
      count++;
   }
   temp2 = temp1->next;
   temp1->next = head3;
   node<t>*head4 = temp2;

   while ( temp2->next != head3 ) {
      temp2 = temp2->next;
   }
   temp2->next = head4;

   return head4 ;
}

void solve() {

   int n;
   cin >> n;
   node<int>*head1 = NULL;
   node<int>*head2 = NULL;
   node<int>*head3 = NULL;

   for (int i = 0; i < n; ++i) {
      // inserAtHead<int>(head1 , 100 + i);
      // inserAtHead<int>(head2 , (-1000) + i);
      inserAtHead<int>(head3 , i + 10);
      inserAtHead<int>(head3 , n - i - 1 + 10);
   }


   // int delNode = 102;
   // cin >> delNode;
   // printCircularLL<int>(head1);
   // deleteNode<int>(head1, delNode);
   // cout << "before concatination : \n";
   // printCircularLL<int>(head1);
   // printCircularLL<int>(head2);

   // cout << "after concatination : \n";
   // concatinateCircularLL(head1, head2);
   // printCircularLL(head1);


   // printCircularLL(head3);
   // removeDuplicates(head3);
   // printCircularLL(head3);

   // cout << "initial list \n";
   // printCircularLL(head3);
   // node<int>*head5 = splitCircularLL(head3);
   // cout << "split list \n";
   // printCircularLL(head3);
   // printCircularLL(head5);

   SingleNode<int>*head_ = NULL;

   for (int i = 0 ; i < n ; i++) {
      insertAtHead<int>(head_ , i + 100 );
   }

   printLL<int>(head_);

   moveLastToFront(head_);
   printLL<int>(head_);


   return;
}


int main() {

   fastInput();

   int t = 1;
   // cin>>t;
   while (t--) {
      solve();
   }

   return 0;
}