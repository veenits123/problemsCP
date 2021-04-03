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

void solve() {
	int n; cin >> n;
	int a[n + 1];
	int S = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		S += a[i];
	}

	int sum = 0, max_till_now = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum < 0)
			sum = 0;
		max_till_now = max(max_till_now, sum);
	}
	//jo_bach_gya = S - max_till_now;
	//invert jo_bach_gya & add max_till_now to it;
	//ans = -(S - max_till_now) + max_till_now;
	int ans = 2 * max_till_now - S;
	cout << ans;

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