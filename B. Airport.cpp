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
	int n, m; cin >> n >> m;
	int small[m], big[m];
	for (int i = 0; i < m; i++) {
		cin >> small[i];
		big[i] = small[i];
	}
	int mx = 0, mn = 0;
	for (int i = 0; i < n; i++) {
		sort(small, small + m);
		sort(big, big + m);
		mx += big[m - 1];
		big[m - 1]--;
		mn += small[0];
		small[0]--;
		if (!small[0])
			small[0] = INT_MAX;
	}
	cout << mx << " " << mn << endl;
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