#include <bits/stdc++.h>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

void solve() {
	int n, k; cin >> n >> k;
	map <int, int> rem;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % k)
			rem[x % k]++;
	}
	// for (auto x : rem)
	// 	cout << x.F << " " << x.S << endl;
	//vector <int> ans;
	int ans = 0;
	if (rem.size()) {
		for (auto x : rem) {
			//method I;

			// int t = k;
			// while (rem[x.F]) {
			// 	ans.pb(t - x.F);
			// 	rem[x.F]--;
			// 	t += k;
			// }

			//method II;
			ans = max(ans, (x.S * k - x.F));
		}
		//method I;
		//sort(ans.begin(), ans.end());//no need to sort in method I;
		//cout << ans[ans.size() - 1] + 1 << endl;

		//method II;
		cout << ans + 1 << endl;
	}
	else {
		cout << 0 << endl;
		return ;
	}

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	int t; cin >> t; while (t--)
		solve();

	return 0;
}