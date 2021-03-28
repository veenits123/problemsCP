#include <iostream>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
	string s; cin >> s;
	int n = s.size();
	int vis[n] = {0};
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if ((s[i] == 'x' && s[i + 1] == 'y' && !vis[i] && !vis[i + 1]) || (s[i] == 'y' && s[i + 1] == 'x' && !vis[i] && !vis[i + 1])) {
			ans++;
			vis[i]++;
			vis[i + 1]++;
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