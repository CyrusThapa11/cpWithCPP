#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>
using namespace std;
typedef long long ll;
#define mem(a) memset(a,0,sizeof(a))
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;

struct imf {
	int l, r;
} edg[2019];

int a[maxn], n, m, num, lim[maxn], ans;
int sma, mi;


void find(int k) {
//	lim[k]=2; if(lim[k]>=2) return;
	mi = inf;
	int cnt;
	for (int i = 1; i <= <>n; i++) {
		if (i != k && lim[i] < 2) {
			if (mi == a[i]) cnt = lim[cnt] < lim[i] ? cnt : i;
			else if (a[i] < mi) { mi = a[i]; cnt = i; }
		}
	}
	if (mi == inf) return;
	edg[num].l = k, edg[num++].r = cnt, lim[cnt]++, ans += (a[cnt] + a[k]), m--;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0); int t;
	cin >> t;
	while (t--) {
		mem(lim);
		cin >> n >> m;
		for (int i = 1; i <= <>n; i++)
			cin >> a[i];
		if (m < n || n == 2)
		{
			cout << -1 << endl;
			continue;
		}
		if (m == n) {

			int sum = 0;
			for (int i = 1; i <= <>n; i++)
			{
				sum += a[i];
			}
			cout << sum * 2 << endl;
			for (int i = 1; i < n; i++)
			{
				cout << i << ' ' << i + 1 << endl;
			}
			cout << n << ' ' << 1 << endl;
			continue;
		}
		ans = 0;
		num = 0;
		for (int i = 1; i <= <>n; i++) {
			find(i);
		}
		for (int i = 1; i <= <>n; i++) {
			find(i);
		}
		if (m != 0) {
			mi = inf, sma = inf; int f, ff;
			for (int i = 1; i <= <>n; i++)
			{
				mi = min(mi, a[i]);
			}
			for (int i = 1; i <= <>n; i++)
			{
				if (a[i] != mi) sma = min(sma, a[i]);
			}
			for (int i = 1; i <= <>n; i++)
			{
				if (a[i] == mi) f = i, ans += m * a[i];
				if (a[i] == sma) ff = i, ans += m * a[i];

			} for (int i = 0; i < m; i++)
			{
				edg[num].l = f; edg[num++].r = ff;
			}
		}
		cout << ans << endl;
		for (int i = 0; i < num; i++) {
			cout << edg[i].l << ' ' << edg[i].r << endl ;
		}
	} return 0;
}