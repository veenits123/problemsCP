#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

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
using u64 = uint64_t;
using u128 = __uint128_t;

const int N = 1e5 + 5;

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

bool is_prime(int n, int it = 5) {
	if (n < 4)
		return n == 2 || n == 3;
	REP(i, 1 h nt a = 2 + rand() % (n - 3);
		int res = binpow(a, n - 1, n);
		if (res != 1)
			return false;
	}
	return true;
}

void solve() {

	int n, k; cin >> n >> k;
	bool flag = false;
	if (is_prime(n) && k == 1) {
		flag = true;
	}
	if (is_prime(n) && k == 1 && n == 2 * k) {
		flag = true;
	}
	if ((n >= 2 * k && is_prime(n - 2) && k == 2 && n & 1) ||
	        ((n & 1 ^ 1) && k == 2 && n >= 2 * k)) {
		flag = true;
	}
	if (n >= 2 * k && k >= 3) {
		flag = true;
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t; while (t--)
		solve();

	return 0;
}