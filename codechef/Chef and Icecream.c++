#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (a[0] != 5) {
		cout << "NO" << endl;
		return ;
	}
	int ans = 0;
	map <int, int> paisa;
	paisa[5] = 0;
	paisa[10] = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (x == 5) {
			ans++;
			paisa[5]++;
		}
		else if (x == 10) {
			paisa[10]++;
			if (paisa[5] >= 1) {
				ans++;
				paisa[5]--;
			}
		}
		else if (x == 15) {
			if (paisa[10] >= 1) {
				ans++;
				paisa[10]--;
			}
			else {
				if (paisa[5] >= 2) {
					ans++;
					paisa[5] -= 2;
				}
			}
		}
	}
	// for(auto x:paisa)
	// 	cout<<x.second<<" ";
	if (ans >= n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}