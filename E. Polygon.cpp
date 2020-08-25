#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n; cin >> n;
	int grid[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char x; cin >> x;
			grid[i][j] = x - '0';
		}
	}
	bool ans = true;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (grid[i][j] && !grid[i + 1][j] && !grid[i][j + 1]) {
				ans = false;
			}
		}
	}
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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

	int t; cin >> t; while (t--) {
		solve();
	}

	return 0;
}