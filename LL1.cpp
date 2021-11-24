#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void fastInput() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
// }


template<typename T>
class node {
public:
    T data;
    node<T> *next;
    node(T d) {
        data = d;
        next = NULL;
    }
};

template<typename T>
class DoubleNode {
public:
    T data;
    DoubleNode<T> *next;
    DoubleNode<T> *prev;
    DoubleNode(T d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};



template<typename T>
void insertAtTail( node<T> *&root, T d ) {
    if (root == NULL) {
        root = new node<T>(d);
        return;
    }

    node<T> *temp = root;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node<T>(d);

    return;
}


template<typename T>
void insertAtHead( node<T>*&root, T d ) {
    if (root == NULL) {
        root = new node<T>(d);
        return;
    }

    node<T>*temp = new node<T>(d);

    temp->next = root;
    root = temp;

    return;
}


template<typename T>
void printLL2(DoubleNode<T>* root) {
    DoubleNode<T>*temp = root;
    while (temp->next != NULL) {
        cout << temp->data << " " ;
        temp = temp -> next;
    }
    cout << temp->data << " ";
    cout << endl;
    return;
}

template<typename T>
void printLL(node<T>* root) {
    node<T>*temp = root;
    while (temp->next != NULL) {
        cout << temp->data << " " ;
        temp = temp -> next;
    }
    cout << temp->data << " ";
    cout << endl;
    return;
}

template<typename T>
void insertAtPos( node<T>*&root, T d , int pos ) {
    if (root == NULL) {
        root = new node<T>(d);
        return;
    }
    if (pos == 1) {
        node<T>*temp3 = new node<T>(d);
        temp3->next = root;
        root = temp3;
        return;
    }

    node<T>*temp = root;
    int ptr = 1;
    while (temp->next != NULL && ptr < pos - 1 ) {
        temp = temp->next;
        ptr++;
    }
    // temp->next = new node(d);
    node<T>*temp2 = temp->next;
    node<T>* insertNode = new node<T>(d);
    temp->next = insertNode;
    insertNode->next = temp2;

    return;
}


template<typename T>
void countNodes( node<T>*root ) {
    int count = 0, minn = INT_MAX, maxx = INT_MIN;
    node<T>*temp = root;
    while (temp != NULL) {
        minn = min(temp->data, minn);
        maxx = max(temp->data, maxx);
        temp = temp->next;
        count++;
    }

    cout << "count " << count << " minn " << " " << minn << " " << " maxx " << maxx;
    return;
}

template<typename T>
void numberToLinkList(node<T>*&head2, int num) {

    int tempNo = num;

    while (tempNo > 0) {
        int dig = tempNo % 10;
        tempNo /= 10;
        insertAtHead<int>(head2, dig);
    }

    return;
}

template < typename T>
node<T>* removeVowels(node<T>*& head3, string str) {
    node<T>*temp = head3;
    node<T>*head = NULL;
    node<T>*currPtr = NULL;

    while (temp != NULL) {
        if (temp->data != 'a' && temp->data != 'e' && temp->data != 'i' && temp->data != 'o' && temp->data != 'u') {
            // cout << temp->data << " ";

            if (head == NULL) {
                head = temp;
                currPtr = head;

            }
            else {
                currPtr->next = temp;
                // cout << currPtr->data << " currPtr data \n";
                currPtr = currPtr->next;
            }
        }

        temp = temp -> next;
    }
    currPtr ->next = NULL;

    return head;
}

template < typename T>
node<T>* stringToLinkList(node<T>*& head3, string str, bool vowels = 0) {

    reverse(str.begin(), str.end());
    for (int i = 0 ; i < str.length() ; i++) {
        insertAtHead<char>(head3, str[i]);
        // cout << str[i] << endl;
    }
    // printLL<char>(head3);
    // cout << endl;

    if (vowels) {
        return removeVowels(head3, str);
    }

    return head3 ;
}

// bool check(node<T>* head4, node<T>* head5) {

// }

template<typename T>
void removeRepeatingCharts(node<T>*& head4, node<T>*& head5) {

    node<T>*temp1 = head4;
    node<T>*temp2 = head5;

    while (temp2->next != NULL) {

        node<T>*currNode = temp2;
        node<T>*temp3 = temp1;
        cout << currNode->data << " , " << temp3->data << endl;

        while ( temp3->next != NULL && temp3->next->data != currNode->data) {
            temp3 = temp3->next;
            cout << temp3->data << " - > " << currNode->data << " ";
        }
        cout << endl;
        node<T>*prevNode = temp3;

        node<T>*next1 = temp3->next->next;
        node<T>*next1_ = temp2->next;
        if (next1 == NULL || next1_ == NULL) {
            temp2 = temp2->next;
            cout << "HI \n";
            continue;
        }

        //     node<T>*next2 = next1->next;
        //     node<T>*next2_ = next1_->next;
        //     if (next2 == NULL || next2_ == NULL ) {
        //         temp2 = temp2->next;
        //         continue;
        //     }

        //     if (next1_->data == next1 -> data && next2_->data == next2->data) {
        //         prevNode->next = next2->next;
        //         // delete ( next2);
        //         // delete ( next1);
        //         // delete ( temp3->next);
        //     }
        // }

        temp2 = temp2->next;
    }
}

template<typename T>
void insertAtHeadDoubleLL(DoubleNode<T>*&root , T data_ ) {
    if (root == NULL) {
        root = new DoubleNode<T>(data_);
        return;
    }

    DoubleNode<T>*temp = new DoubleNode<T>(data_);
    temp->next = root;
    root->prev = temp;

    root = temp;

    return;
}

template<typename T>
void insertAtPosDouble(DoubleNode<T>*&root, T d, int pos) {
    if (root == NULL) {
        root = new DoubleNode<T>(d);
        return;
    }
    if (pos == 1) {
        DoubleNode<T>*temp3 = new DoubleNode<T>(d);
        temp3->next = root;
        root->prev = temp3;
        root = temp3;
        return;
    }

    DoubleNode<T>*temp = root;
    int ptr = 1;

    while (temp->next != NULL && ptr < pos - 1 ) {
        temp = temp->next;
        ptr++;
    }

    // temp->next = new DoubleNode(d);
    DoubleNode<T>*temp2 = temp->next;
    DoubleNode<T>* insertNode = new DoubleNode<T>(d);
    temp->next = insertNode;
    insertNode->prev = temp;
    insertNode->next = temp2;
    temp2->prev = insertNode;

    return;
}

template<typename T>
void deleteLast(DoubleNode<T>*&head6) {

    DoubleNode<int>*root = head6;
    while (root->next->next != NULL) {
        root = root->next;
    }

    delete(root->next);
    root ->next = NULL;

    return;
}

template<typename T>
void ExtremeSwap(DoubleNode<T>*&head6) {
    static int position = 1;

    int temp = 1;
    DoubleNode<int>*swapPos1 = head6;
    DoubleNode<int>*swapPos2 = head6;

    while (swapPos1->next != NULL && temp < position ) {
        swapPos1 = swapPos1->next;
        temp++;
    }
    int cnt = 1;

    while (swapPos2->next != NULL ) {
        swapPos2 = swapPos2->next;
    }

    temp = 1;
    while (swapPos2->prev != NULL && temp < position ) {
        swapPos2 = swapPos2->prev;
        temp++;
    }

    swap(swapPos1->data, swapPos2->data);
    position++;

    return;
}

int main() {
    // fastInput();

    DoubleNode<int>* head6 = NULL;
    for (int i = 1 ; i <= 7 ; i++) {
        insertAtHeadDoubleLL<int>(head6, i + 10);
    }
    printLL2<int>(head6);
    ExtremeSwap<int>(head6);
    cout << "after 1 swap \n";
    printLL2<int>(head6);

    ExtremeSwap<int>(head6);
    cout << "after 2 swap \n";

    printLL2<int>(head6);

    ExtremeSwap<int>(head6);
    cout << "after 3 swap \n";

    printLL2<int>(head6);

    // insertAtPosDouble<int>(head6, 10, 3);
    // printLL2<int>(head6);

    // deleteLast<int>(head6);
    // printLL2<int>(head6);



    // node<char>* head3 = NULL;
    // string str;
    // cin >> str;
    // node<char>* newHead =  stringToLinkList(head3, str, 1);
    // printLL<char>(head3);

    // node<int>*head2 = NULL;
    // int num;
    // cin >> num;
    // numberToLinkList<int>(head2, num);
    // printLL<int>(head2);

    // node<int>*head = NULL;
    // int n;
    // cin >> n;

    // for (int i = 0 ; i < n ; i++) {
    //     insertAtTail<int>(head , i + 100 );
    // }

    // printLL<int>(head);

    // countNodes<int>(head);
    // cout << endl;
    // for (int i = 0 ; i < n ; i++) {
    //     insertAtHead<int>(head , i + 100);
    // }
    // printLL<int>(head);

    // insertAtPos<int>(head, 10000, 3);
    // printLL<int>(head);





// node<char>*head4 = NULL;
// node<char>*head5 = NULL;

// string str1, str2;
// cin >> str1 >> str2;
// head4 = stringToLinkList<char>(head4, str1);
// head5 = stringToLinkList<char>(head5, str2);
// printLL(head4);
// printLL(head5);
// removeRepeatingCharts(head4, head5);
// printLL(head4);

// q8



}