
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n , minn = INT_MAX, num , foundMin = 1 , minIndex = -1;
	cin >> n;

	for (long long int i = 0; i < n; ++i) {
		cin >> num;
		if (minn == num) {
			foundMin = 0;
		}
		else if (minn > num) {
			foundMin = 1;
			minn = num;
			minIndex = i;
		}
	}

	if (foundMin)cout << minIndex + 1 << endl;
	else cout << "Still Rozdil" << endl;

	return 0;
}