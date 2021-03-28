#include <bits/stdc++.h>
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
	vector <int> a;
	int p = 1;
	while (n) {
		int rem = n % 10;
		if (rem)
			a.pb(rem * p);
		n /= 10;
		p *= 10;
	}
	cout << a.size() << endl;
	for (auto x : a)
		cout << x << " ";
	cout << endl;
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