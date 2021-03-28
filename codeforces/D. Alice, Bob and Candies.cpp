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
	int n; cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int moves = 0, alice = 0, bob = 0;
	int suml = 0, sumr = 0;
	int l = 1, r = n;
	while (l <= r) {
		int acur = 0, bcur = 0;
		if (moves % 2 & 1 ^ 1) {
			while (l <= r && acur <= sumr) {
				acur += a[l++];
				//alice+=acur;
			}
			suml = acur;
		}
		else {
			while (l <= r && bcur <= suml) {
				bcur += a[r--];
				//bob+=bcur;
			}
			sumr = bcur;
		}
		alice += acur, bob += bcur;
		moves++;
	}
	cout << moves << " " << alice << " " << bob << endl;
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