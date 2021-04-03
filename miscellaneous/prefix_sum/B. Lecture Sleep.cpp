#include <iostream>
#include <algorithm>
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
	int a[n + 1], t[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> t[i];

	int ans = 0;

	int prefix[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		if (i > 1)
			prefix[i] += prefix[i - 1];

		if (t[i] == 0)
			prefix[i] += a[i];

		if (t[i] == 1) {
			ans += a[i];
			a[i] = 0;
		}
	}
	int res = 0;
	for (int i = k; i <= n; i++) {
		if (i - k >= 1)
			res = max(res, prefix[i] - prefix[i - k]);
		else
			res = max(res, prefix[i]);
		//cout << prefix[i] - prefix[i - k] << " ";
	}
	//cout << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << prefix[i] << " ";
	//cout << endl;

	cout << ans + res;

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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}