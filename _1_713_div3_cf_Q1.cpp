#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n - 2; ++i) {
			if (arr[i] != arr[i + 1] && arr[i] == arr[i + 2] ) {cout << i + 1; break;}
			else if (arr[i] != arr[i + 1] && arr[i + 1] == arr[i + 2]) {cout << i; break;}
			else if (arr[i] != arr[i + 2] && arr[i + 1] == arr[i ]) {cout << i + 2; break;}
		}

		cout << endl;
	}

	return 0;
}