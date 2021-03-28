#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int
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
		int n; cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		a.pb(100);

		int c = 0, xx = 0;
		vector <int> b;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if ((a[i + 1] - a[i]) <= 2) {
				c++;
				flag = true;

			}
			else {
				if (flag) {
					b.pb(c + 1);
					c = 0;
					//flag=false;
				}
				else {
					xx = 1;
					b.pb(1);
				}

			}
		}
		if (b.size() == 0) {
			cout << 1 << " " << 1 << endl;
		}
		else if (b.size() == 1) cout << b[0] << " " << b[0] << endl;
		else {
			sort(b.begin(), b.end());
			if (xx == 1) cout << 1 << " " << b[b.size() - 1] << endl;
			else cout << b[0] << " " << b[b.size() - 1] << endl;
		}

	}


	return 0;
}