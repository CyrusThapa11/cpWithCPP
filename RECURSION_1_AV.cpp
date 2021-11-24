#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;

typedef                 unsigned long long ull;
typedef                 long double lld;

#define ff              first
#define ss              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)


#define fri(a,b,step)   for( ll i = a; i < b; i+=step)
#define frj(a,b,step)   for( ll j = a; j < b; j+=step)
#define frvar(var,a,b,step)   for( ll var = a; var < b; var+=step)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//-----------------------------------------------------------------------------

// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
// #define pb push_back
// #define ppb pop_back

// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//---------------------------------------------------------------------------
void fastInput() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

}


void insertt(vector<int>&vec, int elem) {
    if (vec.size() == 0 || vec[vec.size() - 1] <= elem ) {
        vec.push_back(elem);
        return;
    }

    int currElem = vec[vec.size() - 1];
    vec.pop_back();
    insertt(vec, elem);
    vec.push_back(currElem);

    return;
}

void sortt(vector<int>&vec) {

    if (vec.size() == 1)return;

    int currElem = vec[vec.size() - 1];
    vec.pop_back();

    sortt(vec);

    insertt(vec, currElem);

    return;
}

void insertStk(stack<int>&stack_, int elem) {

    // Reverse-sort
    if (stack_.size() == 0 || stack_.top() >= elem) {
        stack_.push(elem);
        return;
    }

    // sort
    // if (stack_.size() == 0 || stack_.top() <= elem) {
    //     stack_.push(elem);
    //     return;
    // }


    int currElem = stack_.top();
    stack_.pop();

    insertStk(stack_, elem);
    stack_.push(currElem);

    return;
}


void sortStk(stack<int>&stack_) {
    if (stack_.size() == 1)return;

    int elem = stack_.top();
    stack_.pop();

    sortStk(stack_);

    insertStk(stack_, elem);

    return;
}

void revvStk( stack<int>& stack_ ) {

    if (stack_.size() == 1)return;

    int currElem = stack_.top();

    stack_.pop();

    revvStk(stack_);
    insertStk(stack_, currElem);

    return;
}

void printWithSpaces(string string_, string op) {

    if (string_.length() == 0) {
        cout << op << "\n";
        return;
    }

    string op1 = op , op2 = op;

    if (op.length() >= 1 && op[op.size() - 1] != '_' && string_.length() >= 1   ) {
        op1.push_back('_');
        // op2.push_back('_');
    }

    op1.push_back(string_[0]);
    string_.erase(string_.begin());

    printWithSpaces(string_, op1);
    printWithSpaces(string_, op2);
    return;
}

void solve() {

    // SORT VECTOR BY ONLY RECURSION :
    // vector<int>vec(7,0);
    // vec[0] = 12;
    // vec[1] = 2;
    // vec[2] = 112;
    // vec[3] = 0;
    // vec[4] = -12;
    // vec[5] = 10;
    // vec[6] = -12;

    // sortt(vec);
    // for(auto el:vec)cout<<el<<" ";

    //SORT A STACK BY RECURSION :

    stack<int>stack_;

    // 12 -12 102 112 -12 1002 120 -> -12 -12 0 12 102 112 120 1002
    // stack_.push(12);
    // stack_.push(-12);
    // stack_.push(102);
    // stack_.push(0);
    // stack_.push(112);
    // stack_.push(-12);
    // stack_.push(1002);
    // stack_.push(120);

    // sortStk(stack_);
    // cout << stack_.size() << "\n";

    // while (!stack_.empty()) {
    //     cout << stack_.top() << " ";
    //     stack_.pop();
    // }
    // cout << '\n';

    // REVERSE A STACK :

    // revvStk(stack_);
    // while (!stack_.empty()) {
    //     cout << stack_.top() << " ";
    //     stack_.pop();
    // }
    // cout << '\n';

    string string_ = "ABCD" , op = "";

    printWithSpaces(string_, op);










    return;
}


int main() {

    fastInput();

    ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}

