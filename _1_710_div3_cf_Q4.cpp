
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;

bool cmpr(const int&a, const int &b) {
	return a > b;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	map<int, int>mapp;
	while (t--) {
		long long int n , ans = 0;
		cin >> n;
		// long long int arr[n];
		for (int i = 0; i < n; ++i)
		{	cin >> ans;
			mapp[ans]++;
		}
		int max1 = 0;
		// sort(arr, arr + n, cmpr);
		int i = 0;
		for (auto i : mapp) {
			max1 = max(max1, i.second);
		}
		debug(max1);

		// cout << 2 * i;
		ans = n - max1;

		debug(ans);
		ans = min(ans, n / 2);

		debug(ans);
		// ans = n - 2 * i ;
		cout << n - 2 * ans << endl;


	}

	return 0;
}