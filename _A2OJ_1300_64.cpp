
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define debug(x) cout<<#x<<" "<<x<<endl;

//----------------------------------------------------------------------------------


using namespace std;

void init_code() {
	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	init_code();
	int t = 1;
	// cin >> t;
	while (t--) {

		int time = 0, sx = 0, sy = 0, ex = 0, ey = 0;
		cin >> time >> sx >> sy >> ex >> ey;
		string direction;

		cin >> direction;
		int len = time;
		int timeTaken = 0 , canTheySailInX =  0 , canTheySailInY = 0;

		while (time) {

			char drxn = direction [len - time];


			if ( drxn == 'S' || drxn == 'N') {

				if (ey == sy) {
					canTheySailInY = 1 ;
					// cout << "hello" << endl;
				} else {
					if ((ey > sy ) && ( drxn == 'N')) {
						sy++;

					} else if (ey < sy && drxn == 'S') {
						sy--;

					}
				}


			} else {


				if (ex == sx) {
					canTheySailInX = 1 ;

				}
				else {
					if ((ex > sx) && (drxn == 'E')) {
						sx++;

					} else if ((ex < sx) && ( drxn == 'W')) {
						sx--;
					}
				}

			}

			if (ey == sy) {
				canTheySailInY = 1 ;
			}

			if (ex == sx) {
				canTheySailInX = 1 ;
			}



			timeTaken++;
			time--;

			if (canTheySailInX && canTheySailInY) {
				break;
			}

		}

		if (canTheySailInX && canTheySailInY) {
			cout << timeTaken << endl;
		} else
			cout << -1;


	}
	return 0;
}
