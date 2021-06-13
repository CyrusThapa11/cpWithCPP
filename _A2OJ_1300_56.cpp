#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;

bool cmpr(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s, n;
	cin >> s >> n;
	bool won = 1;
	std::vector<pair<int, int>> dragonPower;
	while (n--) {
		int x, y;
		cin >> x >> y;
		dragonPower.push_back({x, y}) ;
	}

	sort(dragonPower.begin(), dragonPower.end(), cmpr);

	for (auto &pairr : dragonPower) {

		// debug(s);
		if (s > pairr.first) {
			s += pairr.second;

		} else {
			won = 0;
			break;

		}

		// cout << pairr.first << " " << pairr.second << endl;
	}

	if (won)cout << "YES";
	else cout << "NO";


	return 0;
}