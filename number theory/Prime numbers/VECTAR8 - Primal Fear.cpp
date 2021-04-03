#include <iostream>
#include <vector>
#include <cmath>
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
vector <int> ans(N);

void sieve() {

	is_prime[0] = is_prime[1] = true;//very important costs many WA & time :|

	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
		}
	}
}

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

bool afraid(int n) {
	int temp = n;
	int dig = 0;
	while (n) {
		if (n % 10 == 0)
			return false;
		dig++;
		n /= 10;
	}
	n = temp;
	int mul = binpow(10, dig - 1);

	while (n) {
		n %= mul;
		mul /= 10;
		if ((n != 0 && is_prime[n]))//is_prime[0] = is_prime[1] = true;
			return false;
	}
	return true;
}

void calc() {
	for (int i = 2; i <= N; i++) {
		ans[i] = ans[i - 1];
		if (!is_prime[i]) {
			if (afraid(i))
				ans[i]++;
		}
	}
}

void solve() {

	int n; cin >> n;
	cout << ans[n] << endl;

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
	calc();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}