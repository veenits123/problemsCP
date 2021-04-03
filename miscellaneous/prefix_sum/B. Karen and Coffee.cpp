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
const int N = 2e5 + 5;
int a[N], prefix[N];

void solve() {
	int n, k, q; cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		a[x]++;
		a[y + 1]--;
	}
	for (int i = 1; i <= N; i++) {
		a[i + 1] += a[i];
		if (a[i] >= k) {
			prefix[i] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		prefix[i + 1] += prefix[i];
	}
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		cout << prefix[y] - prefix[x - 1] << endl;
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