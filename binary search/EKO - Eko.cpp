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

bool check(int a[], int n, int m, int mid) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (mid <= a[i])
			ans += a[i] - mid;
	}
	if (ans >= m)
		return true;
	return false;
}

void solve() {
	int n, m; cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	int low = 0, high = a[n - 1];
	int ans = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (check(a, n, m, mid)) {
			ans = mid;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}