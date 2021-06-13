#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n ;
	cin >> n;
	// n = 13;

	long long int arr[45];
	long long int a = 0 , b = 1 , c ;
	arr[0] = 0 ;
	arr[1] = 1;
	unordered_map<int, int>lookup;
	lookup[0] = 1;
	lookup[1] = 1;

	for (int i = 2; i <= 45; ++i) {
		c = a + b;
		lookup[c] = 1;
		a = b ;
		b = c;
	}

	auto it = lookup.begin();
	bool found = 0;
	for ( ; it != lookup.end(); it++) {
		for (auto it2 = lookup.begin(); it2 != lookup.end(); it2++) {
			for (auto it3 = lookup.begin() ; it3 != lookup.end() ; it3++) {

				a = it->first;
				b = it2->first;
				c = it3->first;

				if ( c + a + b == n ) {
					cout << a << " " << b << " " << c << endl;
					found = 1;
					break;
				}

			}
			if (found)break;
		}
		if (found)break;
	}






	return 0;
}