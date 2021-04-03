#include <iostream>
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
	int n, k; cin >> n >> k;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int max_sum = 0;
	for (int i = 1; i <= k; i++)
		max_sum += a[i];

	int cur_window = max_sum;
	P indices;
	for (int i = k + 1; i <= n; i++) {
		//cout << cur_window <<" "<<max_sum<< endl;

		cur_window += a[i] - a[i - k];
		//adding next element & subtracting
		//first window element
		if (cur_window >= max_sum) {
			//cout << i - k << " " << i - 1 << endl;
			indices.F = i - k + 1, indices.S = i;
			cout << i << endl;
		}

		max_sum = max(max_sum, cur_window);
	}
	cout << max_sum << endl;
	cout << indices.F << " " << indices.S << endl;

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