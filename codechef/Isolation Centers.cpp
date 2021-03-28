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

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		string s; cin >> s;
		map <char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		while (q--) {
			int c; cin >> c;
			int ans = 0;
			for (auto x : m) {
				if (x.S > c) {
					ans += x.S - c;
				}
			}
			cout << ans << endl;
		}
	}


	return 0;
}
