#include <iostream>
#include <map>

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
	int a[n], mp[n + 1] = {0};
	//map <int, int> mp; TLE;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (i == j) continue;
			if (sum <= n) {
				ans += mp[sum];
				mp[sum] = 0;
			}
		}
	}
	cout << ans << endl;
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