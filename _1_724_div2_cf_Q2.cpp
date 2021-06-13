#include <bits/stdc++.h>
using namespace std;


bool cmpr(string &a , string &b) {
	if (a.length() < b.length() )return 1;
	else if (a.length() > b.length())return 0;

	return a < b;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<string>set_1;

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {

				string a ;
				a += char(i + 'a');
				a += char(j + 'a');
				a += char(k + 'a');
				// cout << a << endl;
				set_1.insert(a);
				set_1.insert(a.substr(0, 1));
				set_1.insert(a.substr(0, 2));

			}
		}
	}


	vector<string> allPossibleStrings(set_1.begin(), set_1.end());
	sort(allPossibleStrings.begin(), allPossibleStrings.end() , cmpr );

	int t;
	cin >> t;

	while (t--) {
		int n ;
		cin >> n;
		string str;
		cin >> str;

		for (auto stringCombination : allPossibleStrings) {

			string currentCombination = stringCombination;
			int len = currentCombination.length();
			int count = 0;
			for (int i = 0; i <= n - len ; ++i) {
				if ( str.substr(i, len) == currentCombination ) {
					count = 1;
					break;
				}
			}

			if (!count) {
				cout << currentCombination << endl;
				break;
			}
		}

	}

	return 0;
}