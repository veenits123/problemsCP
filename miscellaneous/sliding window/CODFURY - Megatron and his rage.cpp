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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int max_pla = 0, cur_pla = 0;
	int max_robo = 0, cur_robo = 0;
	int p = 0;
	for (int i = 0; i < n; i++) {
		cur_robo += a[i];
		while (cur_robo > k) {
			cur_robo -= a[p];
			p++;
		}
		cur_pla = i - p + 1;
		if (cur_pla > max_pla) {
			max_robo = cur_robo;
			max_pla = cur_pla;
		}
		if (cur_pla == max_pla) {
			max_robo = min(max_robo, cur_robo);
		}
	}
	cout << max_robo << " " << max_pla << endl;

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