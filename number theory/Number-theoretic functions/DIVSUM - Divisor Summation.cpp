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
vb is_prime(N);
vi prime;

void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i <= N; i += 2) {
		if (!is_prime[i])
			prime.pb(i);
	}
}

int binpow(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int sum(int n) {
	int ans = 1;
	int temp;
	for (int x : prime) {
		if (x * x > n)
			break;
		if (n % x == 0) {
			int cnt = 0;
			while (n % x == 0) {
				cnt++;
				n /= x;
			}
			temp = binpow(x, cnt + 1) - 1;
			ans *= temp / (x - 1);
		}
	}
	if (n > 1) {
		temp = binpow(n, 1 + 1) - 1;
		ans *= temp / (n - 1);
	}
	return ans;
}

int summation(int n) {
	int ans = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int d1 = i;
			int d2 = n / i;
			cout << d1 << " " << d2 << endl;
			if (d1 == d2)
				ans += d1;
			else
				ans += d1 + d2;
		}
	}
	return ans;
}

void solve() {

	int n; cin >> n;
	cout << summation(n) - n << endl;

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

	//sieve();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}