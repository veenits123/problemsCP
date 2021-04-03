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

bool is_valid(int mid, int a[], int n, int c) {
	int prev = -1e12;//previously placed cow; & a[i] is current cow;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - prev >= mid) {
			cnt++;
			prev = a[i];
		}
		//cout << prev << " ";
	}
	return cnt >= c;
}

void solve() {
	int n, c; cin >> n >> c;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	int low = 0, high = a[n - 1] - a[0];
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (is_valid(mid, a, n, c)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << endl;

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