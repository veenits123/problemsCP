#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
	int n, x; cin >> n >> x;
	vector <int> a(n, 0);
	set <int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	if (s.size() == 1) {
		int c = 1;
		while (a[0] > x) {
			x *= 2;
			c++;
			//cout << x << " ";
		}
		cout << c + n - 1 << endl;
		return ;
	}
	int days = 0;
	while (true) {
		auto it = lower_bound(a.begin(), a.end(), x);
		//cout<<x<<" ";

		while (*it > x) {
			x *= 2;
			days++;
		}
		if (it == a.end()) {
			days += n;
			break;
		}
	}
	cout << days << endl;

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
