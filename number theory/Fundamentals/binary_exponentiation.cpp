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

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			n--;
		}
		a *= a;
		n >>= 1;
	}
	return res;
}

//effective computation of large exponents modulo a number;
int mod_exp(int a, int n, int mod) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (res * a) % mod;
			n--;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

void solve() {
	int a, n, m; cin >> a >> n >> m;
	cout << mod_exp(a, n, m) % m;

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