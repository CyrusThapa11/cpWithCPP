
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n , m;
	cin >> n ;

	int arr[7];

	for (int i = 0 ; i  < 7 ; i++) {
		cin >> arr[i];

	}

	bool read = 0;
	int i = 7;
	while (1) {

		i = i % 7 ;
		if (  n - arr[i] <= 0 ) {

			// cout << i << " ";
			int pos = i + 1;
			// pos = i == 0 ? 1 : i + 1;
			cout << pos;

			break;
		}

		n -= arr[i++];
	}

	return 0;
}