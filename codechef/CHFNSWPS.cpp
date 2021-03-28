#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

void solve() {
	int n; cin >> n;

	unordered_map<int, int> universal;
	int ans = 0;
	int a[n], b[n];

	unordered_map<int, int> array;
	int minimum = 1e9 + 5;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		array[a[i]]++;
		universal[a[i]]++;
		minimum = min(minimum, a[i]);
	}

	unordered_map<int, int> array2;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		array2[b[i]]++;
		universal[b[i]]++;
		minimum = min(minimum, b[i]);
	}
	sort(a, a + n);
	sort(b, b + n);
	int mn = min(a[0], b[0]);

	vector<int> aaa, bbb;
	for (int i = 0; i < n; i++) {
		int count, freq, kitna_baar;
		count = universal[a[i]];
		count /= 2;
		freq = array[a[i]];
		kitna_baar = (freq - count);
		if (array[a[i]] != 0 && kitna_baar > 0) {
			while (kitna_baar--) {
				aaa.pb(a[i]);
			}
			array[a[i]] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int count, freq, kitna_baar;
		count = universal[b[i]];
		count = count / 2;
		freq = array2[b[i]];
		kitna_baar = (freq - count);
		if (array2[b[i]] != 0 && kitna_baar > 0) {
			while (kitna_baar--) {
				bbb.pb(b[i]);
			}
			array2[b[i]] = 0;
		}
	}

	for (auto x : universal) {
		if (x.S % 2) {
			cout << -1 << endl;
			return ;
		}
	}
	if (aaa.size() == 0) {
		cout << ans << endl;
		return ;
	}
	else {
		sort(aaa.begin(), aaa.end());
		sort(bbb.begin(), bbb.end(), greater<int>());

		for (int i = 0; i < aaa.size(); i++) {
			int option1 = min(aaa[i], bbb[i]);
			int option2 = mn * 2;
			ans += min(option2, option1);
		}

		cout << ans << endl;
		return ;
	}

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	FIO;

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