#include <iostream>
#include <vector>
#include <algorithm>
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

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> lhs, rhs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				lhs.pb(a[i]*a[j] + a[k]);
				if (a[i])
					rhs.pb(a[i] * (a[j] + a[k]));
			}
		}
	}
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());

	//method-I;
	// map <int, int> l, r;
	// for (int i = 0; i < lhs.size(); i++)
	// 	l[lhs[i]]++;
	// for (int i = 0; i < rhs.size(); i++)
	// 	r[rhs[i]]++;
	// int ans = 0;
	// for (auto x : l)
	// 	ans += x.S * r[x.F];
	// cout << ans << endl;

	//method-II;
	//binary-search;
	int ans = 0;
	for (int i = 0; i < lhs.size(); i++) {
		int low = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		int high = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		ans += high - low;
	}
	cout << ans << endl;

	return ;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}