#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n; cin >> n;
	if (n < 4) {
		cout << -1 << endl;
		return ;
	}
	else {
		vector <int> a;
		for (int i = n; i >= 1; i--) {
			if (i & 1)
				a.pb(i);
		}
		a.pb(4), a.pb(2);
		for (int i = 6; i <= n; i++) {
			if (i & 1 ^ 1)
				a.pb(i);
		}
		for (auto x : a)
			cout << x << " ";
		cout << endl;
		return ;
	}
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {
		solve();
	}


	return 0;
}