#include <iostream>
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

const int N = 1e6 + 5;
vector <bool> is_prime(N);
vector <int> pp(N);
vector <int> ans(N);

void sieve() {
	//sieving;
	for (int i = 3; i <= N; i += 2) {
		is_prime[i] = true;
	}
	is_prime[2] = true;
	for (int i = 3; i * i <= N; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += 2 * i) {
				is_prime[j] = false;
			}
		}
	}
	//prefix-sum;
	for (int i = 2; i <= N; i++) {
		pp[i] = pp[i - 1];
		if (is_prime[i])
			pp[i]++;
	}
	for (int i = 2; i <= N; i++) {
		if (is_prime[pp[i]])
			pp[i] = 1;
		else
			pp[i] = 0;
	}
	for (int i = 2; i <= N; i++) {
		ans[i] = ans[i - 1] + pp[i];
	}
}

void solve() {
	
	int l, r; cin >> l >> r;
	cout << ans[r] - ans[l - 1] << endl;

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

	sieve();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}