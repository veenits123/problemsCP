#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

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

const int N = 5e5 + 5;

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

int fact[N];
int inv[N];

void init() {
	fact[0] = inv[0] = 1;
	REP(i, 1, N) {
		fact[i] = (i % mod * fact[i - 1] % mod) % mod;
		inv[i] = inverse(fact[i]);
	}
}

int ncr(int n, int r) {
	int denom = inv[r] * inv[n - r] % mod;
	return fact[n] * denom % mod;
}

void solve() {

	int m, n; cin >> m >> n;
	int ans = 0;
	REP(i, 0, m - n) {
		ans = ans % mod +
		      (ncr(m - i - 1, n - 1) % mod * binpow(n, i) % mod * binpow(n - 1, m - n - i) % mod) % mod;
	}
	cout << ans << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}