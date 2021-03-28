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
	int n0, n1, n2; cin >> n0 >> n1 >> n2;
	string s2 = "", s0 = "";
	if (n2) {
		int two = n2 + 1;
		while (two--) s2 += '1';
	}
	if (n0) {
		int zero = n0 + 1;
		while (zero--) s0 += '0';
	}
	if (n1 == 0) {
		if (n2) {
			cout << s2 << endl;
		}
		else {
			cout << s0 << endl;
		}
	} else {
		string ans = "";
		for (int i = 0; i < n1 + 1; i++) {
			if (i & 1) ans += "0";
			else ans += "1";
		}

		ans.insert(1, string(n0, '0'));
		ans.insert(0, string(n2, '1'));

		cout << ans << endl;
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