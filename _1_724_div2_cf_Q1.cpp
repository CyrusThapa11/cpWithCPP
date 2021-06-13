#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin >> t;
	while (t--) {
		int n ;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		bool hasNegativeNum = 0;
		for (int i = 0; i < n; ++i)
			if (arr[i] < 0) {
				hasNegativeNum = 1;
				break;
			}

		if (hasNegativeNum)cout << "NO" << endl;
		else {
			cout << "YES" << endl << n + 1 << endl;
			for (int i = 0; i <= n ; ++i)
				cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}