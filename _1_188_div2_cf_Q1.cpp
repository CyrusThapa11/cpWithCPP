#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned long long maxRows , maxCols , numberr , t;
	cin >> t;

	while (t--) {

		cin >> maxRows >> maxCols >> numberr;
		unsigned long long row , col , total_cells = 0;

		row = numberr % maxRows;
		col = numberr - row;
		col = col / maxRows + 1;
		row = row == 0 ? 1 : row;
		col = col == 0 ? 1 : col;
		total_cells += row * col;
		total_cells += (row - 1) * (maxCols - col);
		total_cells = ((maxRows == 1) == maxCols ) ? 1 : total_cells;
		// total_cells == 1 ? 1 : total_cells;
		cout << total_cells << endl;

	}



	return 0;
}