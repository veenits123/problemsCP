#include <iostream>
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
const int N = 1e5 + 5;
int a[N + 1], l[N + 1], r[N + 1], d[N + 1], q[N + 1];
int ans[N + 1];

void solve() {
	int n, m, k; cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++)
		cin >> l[i] >> r[i] >> d[i];

	for (int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		q[x]++;
		q[y + 1]--;
	}

	for (int i = 1; i <= m; i++) {
		q[i + 1] += q[i];
		d[i] = d[i] * q[i];
		ans[l[i]] += d[i];
		ans[r[i] + 1] -= d[i];
	}

	for (int i = 1; i <= n; i++) {
		ans[i + 1] += ans[i];
		a[i] += ans[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}