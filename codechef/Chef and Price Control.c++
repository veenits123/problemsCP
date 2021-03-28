#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
	int n, k; cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > k) {
			ans += a[i] - k;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}