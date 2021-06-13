#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string s;
	cin >> s;
	bool valid = 1;
	int len = s.length();

	for (int i = 0; i < len ;)
	{
		if ( i <= len - 3 && s.substr(i, 3) == "144") {
			i += 3;
			continue;
		} else if (i <= len - 2 && s.substr(i, 2) == "14") {
			i += 2;
			continue;
		}
		else if (i <= len - 1 && s.substr(i, 1) == "1") {
			i++;
			continue;
		} else {
			valid = 0;
			break;
		}
	}

	if (valid)cout << "YES";
	else cout << "NO";


	return 0;
}