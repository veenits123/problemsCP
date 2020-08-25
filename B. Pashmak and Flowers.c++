#include <iostream>
#include <algorithm>

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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int mx = a[n - 1];
	int mn = a[0];
	cout << mx - mn << " ";
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == mx)
			x++;
		if (a[i] == mn)
			y++;
	}
	if (x == n) {
		cout << n*(n - 1) / 2;
		return ;
	}
	else
		cout << x*y;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}