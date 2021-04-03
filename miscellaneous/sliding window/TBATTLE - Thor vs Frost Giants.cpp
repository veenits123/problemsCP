#include <iostream>
#include <vector>
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
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p = 0;
	int cur = 1;
	int ans = 1e6;
	bool flag = false;
	int l, r;
	for (int i = 0; i < n; i++) {
		cur *= a[i];
		if (cur % n == 0) {
			while ((cur /= a[p]) % n == 0) {
				p++;
				if (p >= n)
					break;
				// cout << cur << endl;
			}
			if (p < n)
				cur *= a[p];
			if (ans > (i - p + 1)) {
				ans = min(ans, i - p + 1);
				flag = true;
				//cout << cur << endl;
				//cout << p << " " << i << endl;
				l = p; r = i;
			}
		}
	}
	//cout << ans << endl;
	if (!flag) {
		cout << -1;
		return ;
	}
	cout << l << " " << r;

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