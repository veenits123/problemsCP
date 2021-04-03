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
	int m, k; cin >> m >> k;
	int a[n + 1] = {0};
	int prefix[n + 1];
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		a[y + 1] -= k;
		a[x] += k;
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;

	}
	prefix[1] = a[1];
	for (int i = 2; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i++)
		cout << prefix[i] << " ";

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