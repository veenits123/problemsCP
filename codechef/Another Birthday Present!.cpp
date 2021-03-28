#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < k; i++) {
			int x = 0;
			for (int j = i; j < n; j += k) {
				b[x++] = a[j];
			}
			sort(b, b + x);
			int j = 0;
			for (int x = i; x < n; x += k) {
				a[x] = b[j++];
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[i + 1]) flag = false;
		}
		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}


	return 0;
}