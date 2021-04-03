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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
	u64 result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = (u128)result * base % mod;
		base = (u128)base * base % mod;
		e >>= 1;
	}
	return result;
}

bool probablyPrimeFermat(int n, int iter = 5) {
	if (n < 4)
		return n == 2 || n == 3;

	for (int i = 0; i < iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (binpower(a, n - 1, n) != 1)
			return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	cout << (probablyPrimeFermat(n) ? "YES" : "NO") << endl;

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