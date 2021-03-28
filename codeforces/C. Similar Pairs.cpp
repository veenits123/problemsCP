#include <iostream>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
	int n; cin >> n;
	int a[n];
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
		if (x & 1)
			odd++;
		else
			even++;
	}
	//cout << even << " " << odd << endl;
	if (even % 2 != odd % 2) {
		cout << "NO" << endl;
		return ;
	}
	else {
		if (even & 1 ^ 1) {
			cout << "YES" << endl;
			return ;
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((a[i] % 2 != a[j] % 2) && abs(a[i] - a[j]) == 1) {
						cout << "YES" << endl;
						return ;
					}
				}
			}
			cout << "NO" << endl;
			return ;
		}
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