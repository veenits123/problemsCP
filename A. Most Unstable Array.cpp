#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n, m; cin >> n >> m;
	int x = (n - 1);
	if (x == 0) {
		cout << 0 << endl;
		return ;
	}
	else if (x == 1) {
		cout << m << endl;
		return ;
	}
	else {
		x = x / 2;
		cout << 2 * m << endl;
		return ;
	}
	return ;
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