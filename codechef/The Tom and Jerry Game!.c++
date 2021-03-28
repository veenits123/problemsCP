#include <iostream>
#include <cmath>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
	int ts; cin >> ts;
	if (ts % 2) {
		cout << ts / 2 << endl;
		return ;
	}
	else {
		int i = 0;
		while (ts) {
			ts /= 2;
			if (ts & 1) {
				i = ts;
				break;
			}
		}
		cout << i / 2 << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}