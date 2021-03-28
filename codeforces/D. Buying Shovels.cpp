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
	int n, k; cin >> n >> k;
	int ans = n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i <= k)
				ans = min(ans, n / i);
			if (n / i <= k)
				ans = min(ans, i);
		}
	}
	cout << ans << endl;
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