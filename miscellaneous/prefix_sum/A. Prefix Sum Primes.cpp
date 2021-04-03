#include <iostream>
#include <vector>
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
	vector <int> tw, one;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 1)
			one.pb(x);
		else
			tw.pb(x);
	}
	if (tw.size() == 0) {
		for (int i = 0; i < n; i++)
			cout << one[i] << " ";
		return ;
	}
	else if (one.size() == 0) {
		for (int i = 0; i < n; i++)
			cout << tw[i] << " ";
		return ;
	}
	cout << 2 << " " << 1 << " ";
	tw.pop_back(); one.pop_back();
	for (auto x : tw)
		cout << x << " ";
	for (auto x : one)
		cout << x << " ";

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