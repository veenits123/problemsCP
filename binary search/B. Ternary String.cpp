#include <iostream>
#include <map>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

//sliding window;
// void solve() {
// 	string s; cin >> s;
// 	int n = s.size();
// 	int p = 0;
// 	int ans = 2e6;
// 	int cnt = 0;
// 	map <char, int> m, check;
// 	m['1'] = 1, m['2'] = 1, m['3'] = 1;
// 	for (int i = 0; i < n; i++) {
// 		check[s[i]]++;
// 		if (check[s[i]] == m[s[i]]) {
// 			cnt++;
// 		}
// 		if (cnt == 3) {
// 			while (check[s[p]] > m[s[p]] && p < n) {
// 				check[s[p]]--;
// 				p++;
// 			}
// 			ans = min(ans, i - p + 1);
// 		}
// 	}
// 	if (ans != 2e6)
// 		cout << ans << endl;
// 	else
// 		cout << 0 << endl;

// 	return ;
// }

//binary search;

bool is_valid(string s, int mid) {
	int a[4] = {0};
	for (int i = 0; i < mid - 1; i++)
		a[s[i] - '0']++;
	for (int i = mid - 1; i < s.size(); i++) {
		a[s[i] - '0']++;
		if (a[1] > 0 && a[2] > 0 && a[3] > 0)
			return true;
		a[s[i - mid + 1] - '0']--;
	}
	return false;
}

void solve() {
	string s; cin >> s;
	int n = s.size();

	int low = 3, high = n;
	int ans = 1e9;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (is_valid(s, mid)) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	if (ans != 1e9)
		cout << ans << endl;
	else
		cout << 0 << endl;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	int t; cin >> t; while (t--)
		solve();

	return 0;
}