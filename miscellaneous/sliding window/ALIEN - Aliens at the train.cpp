#include <iostream>
#include <vector>
#include <algorithm>
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

bool comp(P a, P b) {
	if (a.F != b.F)
		return a.F > b.F;
	else
		return a.S < b.S;
}

void solve() {
	int n, k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int p = 0;
	int min_sum = 0, cur_sum = 0;
	int len = 0, max_len = 0;

	//vector <P> res;

	for (int i = 0; i < n; i++) {
		cur_sum += a[i];
		while (cur_sum > k) {
			cur_sum -= a[p];
			p++;
			//len--;
			// if (cur_sum <= k) {
			// 	break;
			// }
		}
		//len++;
		//res.pb({len, cur_sum});
		//or;
		//res.pb({i - p + 1, cur_sum});
		len = i - p + 1;
		if (len > max_len) {
			max_len = len;
			min_sum = cur_sum;
		}
		if (len == max_len) {
			min_sum = min(min_sum, cur_sum);
		}
	}
	//sort(res.begin(), res.end(), comp);
	// for (auto x : res)
	// 	cout << x.S << " " << x.F << endl;
	//cout << res[0].S << " " << res[0].F << endl;
	cout << min_sum << " " << max_len << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}