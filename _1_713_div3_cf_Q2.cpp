
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char arr[n][n];

		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '*' && x1 == -1) {
					x1 = i;
					y1 = j;
				} else if (arr[i][j] == '*') {
					x2 = i;
					y2 = j;
				}
			}


		// for (int i = 1; i <= n; ++i)
		// 	for (int j = 1; j <= n; ++j) {
		// 		if (arr[i][j] == '*' && x1 == -1) {
		// 			x1 = i;
		// 			y1 = j;
		// 		} else if (arr[i][j] == '*') {
		// 			x2 = i;
		// 			y2 = j;
		// 			break;
		// 		}
		// 		if (x2 != -1)break;
		// 	}

		// same row
		if (x1 == x2) {
			if (x1 != n ) {
				arr[x1 + 1][y1] = '*';
				arr[x1 + 1][y2] = '*';
			} else {
				arr[x1 - 1][y1] = '*';
				arr[x1 - 1][y2] = '*';
			}
		} else
			// same col
			if (y1 == y2) {
				if (y1 != n ) {
					arr[x1 ][y1 + 1] = '*';
					arr[x2 ][y1 + 1] = '*';
				} else {
					arr[x1 ][y1 - 1] = '*';
					arr[x2 ][y1 - 1] = '*';
				}
			}
			else {
				arr[x1][y2] = '*';
				arr[x2][y1] = '*';
			}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char arr[n][n];
		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '*' && x1 == -1) {
					x1 = i;
					y1 = j;
				} else if (arr[i][j] == '*') {
					x2 = i;
					y2 = j;
				}
			}
		}

		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

		// for (int i = 1; i <= n; ++i)
		// 	for (int j = 1; j <= n; ++j) {
		// 		if (arr[i][j] == '*' && x1 == -1) {
		// 			x1 = i;
		// 			y1 = j;
		// 		} else if (arr[i][j] == '*') {
		// 			x2 = i;
		// 			y2 = j;
		// 			break;
		// 		}
		// 		if (x2 != -1)break;
		// 	}

		// same row
		if (x1 == x2) {
			if (x1 != n ) {
				arr[x1 + 1][y1] = '*';
				arr[x1 + 1][y2] = '*';
			} else {
				arr[x1 - 1][y1] = '*';
				arr[x1 - 1][y2] = '*';
			}
		} else
			// same col
			if (y1 == y2) {
				if (y1 != n ) {
					arr[x1 ][y1 + 1] = '*';
					arr[x2 ][y1 + 1] = '*';
				} else {
					arr[x1 ][y1 - 1] = '*';
					arr[x2 ][y1 - 1] = '*';
				}
			}
			else {
				arr[x1][y2] = '*';
				arr[x2][y1] = '*';
			}
		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= n; ++j) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}