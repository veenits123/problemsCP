#include <iostream>
#include <vector>
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
	int n, m; cin >> n >> m;
	vector <P> a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			a.pb({x, i});
		}
	}
	sort(a.begin(), a.end());
	// for (auto x : a)
	// 	cout << x.F << " ";
	// cout << endl;
	int total_elem = m * n;
	int left = 0, right = 0;
	int window = 1;
	int diff = 1e9 + 5;

	int cnt[n + 1] = {0};
	cnt[a[0].S]++;

	while (left < total_elem && right < total_elem) {

		if (window == n) {
			diff = min(diff, a[right].F - a[left].F);

			cnt[a[left].S]--;
			if (cnt[a[left].S] == 0) {
				window--;
			}
			left++;
		}
		else {
			right++;
			cnt[a[right].S]++;
			if (cnt[a[right].S] == 1) {
				window++;
			}
			if (right == total_elem)
				break;
		}
	}
	cout << diff << endl;

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