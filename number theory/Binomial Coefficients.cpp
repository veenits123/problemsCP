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
int factorial[N];

void fact() {
	factorial[0] = factorial[1] = 1;
	REP(i, 2, N) {
		factorial[i] = (i * 1LL * factorial[i - 1]) % mod;
	}
}

int binpow(int base, int expo, int m = mod) {
	int res = 1;
	base = base % m;
	while (expo) {
		if (expo & 1) {
			res = (res * 1LL * base) % m;
			expo--;
		}
		expo >>= 1;
		base = (base * 1LL * base) % m;
	}
	return res;
}

int mod_inv(int n, int m = mod) {
	return binpow(n, m - 2);
}

int ncr(int n, int k) {
	if (k > n)
		return 0;
	int res = factorial[n];
	res = (res * 1LL * mod_inv(factorial[k])) % mod;
	res = (res * 1LL * mod_inv(factorial[n - k])) % mod;

	return res;
}

void solve() {

	int n, k; cin >> n >> k;
	cout << ncr(n, k) % mod << endl;

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

	fact();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}