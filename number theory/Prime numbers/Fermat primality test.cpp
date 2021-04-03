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
using u64 = uint64_t;
using u128 = __uint128_t;
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e5 + 5;

//m-I;
u64 binpow(u64 a, u64 n, u64 m) {
	u64 res = 1;
	a = a % m;
	while (n > 0) {
		if (n & 1)
			res = (u128)res * a % m;
		a = (u128)a * a % m;
		n >>= 1;
	}
	return res % m;
}

//m-II;
int multilpy(int a, int b, int m) {
	int x = 0, y = a % m;
	while (b > 0) {
		if (b & 1)
			x = (x + y) % m;
		b >>= 1;
		y = (y + y) % m;
	}
	return x % m;
}

int power(int a, int n, int m) {
	a %= m;
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = multilpy(res, a, m);
		a = multilpy(a, a, m);
		n >>= 1;
	}
	return res % m;
}

bool is_prime(int n, int iter = 5) {
	if (n < 4)
		return n == 2 || n == 3;
	REP(i, 0, iter) {
		int a = 2 + rand() % (n - 3);// 2 <= a <= n-2;
		//m-I;
		//int res = binpow(a, n - 1, n);

		//m-II;
		int res = power(a, n - 1, n);
		if (res != 1)
			return false;
	}
	return true;
}

void solve() {

	int n; cin >> n;
	if (is_prime(n))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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