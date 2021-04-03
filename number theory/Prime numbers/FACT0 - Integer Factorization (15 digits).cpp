#include <iostream>
#include <vector>
#include <array>
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

void prime_factor(int n) {

	for (int d : {2, 3, 5}) {
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				cnt++;
				n /= d;
			}
			cout << d << "^" << cnt << " ";
		}
	}
	//how much we have to skip ;)
	static array<int, 8> skip = {4, 2, 4, 2, 4, 6, 2, 6};

	int i = 0;
	for (int d = 7; d * d <= n; d += skip[i++]) {
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				cnt++;
				n /= d;
			}
			cout << d << "^" << cnt << " ";
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		cout << n << "^" << 1 << " ";
}

void solve() {

	while (true) {
		int n; cin >> n;
		if (n == 0)
			return ;
		prime_factor(n);
		cout << endl;
	}

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

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}