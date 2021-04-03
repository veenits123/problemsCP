#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e6 + 5;
int fact[N];

void init() {
	fact[0] = 1;
	REP(i, 1, N) {
		fact[i] = (i % mod * fact[i - 1] % mod) % mod;
	}
}

int binpow(int a, int n, int m = mod) {
	int res = 1;
	a = a % m;
	while (n > 0) {
		if (n & 1) {
			res = res * a % m;
			n--;
		}
		n >>= 1;
		a = a * a % m;
	}
	return res;
}

int inverse(int a, int m = mod) {
	return binpow(a, m - 2, m);
}

int ncr(int n, int r) {
	int denom = fact[r] % mod * fact[n - r] % mod;
	denom = inverse(denom, mod);
	return fact[n] * denom % mod;
}

bool is_good(int n, int a, int b) {
	while (n > 0) {
		if (n % 10 == a || n % 10 == b)
			n /= 10;
		else
			return false;
	}
	return true;
}

void solve() {

	int a, b, n; cin >> a >> b >> n;
	int ans = 0;
	REP(i, 0, n) {
		int sum = a * i + (n - i) * b;
		if (is_good(sum, a, b)) {
			ans = (ans % mod) + ncr(n, i) % mod;
		}
	}
	cout << ans % mod << endl;

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

	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}