#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n, m; cin >> n >> m;
	int a[n][m];
	int ash = 0, viv = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int r = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)
				r++;
		}
		if (r == m)
			ash++;
	}
	for (int i = 0; i < m; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 0)
				c++;
		}
		if (c == n)
			viv++;
	}

	int ans = min(ash, viv);

	if (ans % 2)
		cout << "Ashish" << endl;
	else
		cout << "Vivek" << endl;
	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--)
		solve();

	return 0;
}