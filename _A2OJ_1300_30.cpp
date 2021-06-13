
#include <bits/stdc++.h>
using namespace std;


#define debug(x) cout<< #x << " "<<x<<endl;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	// map<int, int>mapp;
	int n;
	cin >> n;
	int arr1[n];
	for (int i = 1; i <= n; ++i)
		cin >> arr1[i];

	int m;
	cin >> m;
	int arr2[m];
	long long int LtRComparisions1[100100] = {0} ;
	long long int RtLComparisions2[100100] = {0} ;

	for (int i = 1; i <= m; ++i)
		cin >> arr2[i];

	for (int i = 1; i <= n; ++i)
	{
		LtRComparisions1[arr1[i] ] = i ;
		// debug( arr1[i] - 1);
		// debug(LtRComparisions1[ arr1[i] - 1] );

		RtLComparisions2[arr1[i] ] = n - i + 1;
		// debug(RtLComparisions2[ arr1[i] - 1] );

	}

	long long int LtRComparisionsSum = 0;
	long long int RtLComparisionsSum = 0;

	for (int i = 1; i <= m; ++i)
	{
		LtRComparisionsSum += LtRComparisions1[ arr2[i] ];
		RtLComparisionsSum += RtLComparisions2[ arr2[i] ];

	}
	cout << LtRComparisionsSum << " " << RtLComparisionsSum;
	return 0;
}