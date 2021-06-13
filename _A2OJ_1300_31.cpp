
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<< #x << " "<<x<<endl;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n , m;
	cin >> n >> m;

	queue<pair<int, int>>Queue_;

	for (int i = 1; i <= n; ++i)
	{
		int choco;
		cin >> choco;
		Queue_.push(make_pair(i, choco));
	}


	pair<int, int>pair_;
	while (!Queue_.empty()) {

		pair_ = Queue_.front();
		Queue_.pop();

		if (Queue_.empty())break;

		if (pair_.second > m)
			Queue_.push( make_pair(pair_.first, pair_.second - m) );

	}


	cout << pair_.first;


	return 0;
}