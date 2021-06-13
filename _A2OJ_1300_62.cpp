
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

bool cmpr(pair<int, int>p1, pair<int, int>p2) {
	if (p1.first < p2.first)return 1;
	if (p1.first > p2.first)return 0;
	if (p1.first = p2.first)return p1.second < p2.second;

	return 0;
}

int main() {
	init_code();
	int t = 1;
	// cin >> t;
	while (t--) {

		int n ;
		cin >> n;

		int arr[n] = {0};
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		vector<pair<int, int>>vector_;

		for (int i = 0; i < n; ++i)
			vector_.push_back({arr[i], i });

		int numer = 0;
		set<pair<int, int>>set_;
		sort(vector_.begin(), vector_.end(), cmpr);

		for (int i = 0; i < n; ++i) {

			pair<int, int>currPair = vector_[i];

			int currNo = currPair.first ;
			int currPos = currPair.second;
			int commonD = 0 , isAp = 1;

			i++;

			while (vector_[i].first == currNo) {

				if (commonD == 0)
					commonD = vector_[i].second - currPos;
				else if (commonD != 0) {

					if (commonD != vector_[i].second - vector_[i - 1].second )
						isAp = 0;
				}
				i++;
			}

			if (isAp)
				set_.insert({currNo, commonD});

			i--;
		}

		cout << set_.size() << endl;

		for (auto i : set_)
			cout << i.first << " " << i.second << endl;

	}
	return 0;
}
