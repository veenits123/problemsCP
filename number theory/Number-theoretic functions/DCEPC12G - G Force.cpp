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

#define int long long int
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

const int N = 1e7 + 5;
vb is_prime(N);

int prime[N];
void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
		}
	}
	REP(i, 2, N) {
		prime[i] = prime[i - 1];
		if (!is_prime[i])
			prime[i]++;
	}
}

int phi[N];
void etf() {
	REP(i, 1, N)
	phi[i] = i;

	REP(i, 2, N) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
}

int binpow(int a, int n, int m = mod) {
	a = a % m;
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * a % m;
		n >>= 1;
		a = a * a % m;
	}
	return res % m;
}

void solve() {

	int n; cin >> n;
	int fn = prime[n] - phi[n];
	if (fn < 0)
		fn = 0;

	int factorial = 1;
	if (fn > 1) {
		REP(i, 1, fn) {
			factorial = factorial * i;
		}
	}

	cout << binpow(phi[n], factorial) % mod << endl;

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
	etf();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}