#include <iostream>
#include <cmath>
#include <vector>
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

typedef vector<bool> vb;
typedef vector<int> vi;

//method-I : pre-calculating primes till sqrt(r);
vector <bool> segmented_sieve(int l, int r) {

	int lim = sqrt(r);
	vector <bool> mark(lim + 1, true);
	vector <int> prime;
	mark[0] = mark[1] = false;
	for (int i = 2; i <= lim; i++) {
		if (mark[i]) {
			prime.pb(i);
			for (int j = i * i; j <= lim; j += i) {
				mark[j] = false;
			}
		}
	}
	vector <bool> arr(r - l + 1, true);

	for (auto x : prime) {
		for (int i = max(x * x, ((l + x - 1) / x) * x); i <= r; i += x) {
			arr[i - l] = false;
		}
	}
	if (l == 1)
		arr[0] = false;
	return arr;
}

//method-II : not pre-calculating primes;
// vector <bool> segmented_sieve(int l, int r) {

// 	vector <bool> arr(r - l + 1, true);
// 	for (int i = 2; i * i <= r; i++) {
// 		for (int j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i) {
// 			arr[j - l] = false;
// 		}
// 	}
// 	if (l == 1)
// 		arr[0] = false;
// 	return arr;
// }

void solve() {
	int n, m; cin >> n >> m;
	vector <bool> ans = segmented_sieve(n, m);
	// for (auto x : ans)
	// 	cout << x << " ";
	// cout << endl;
	for (int i = n; i <= m; i++) {
		if (ans[i - n])
			cout << i << endl;
	}

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