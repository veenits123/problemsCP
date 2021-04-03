#include <iostream>
#include <vector>
#include <algorithm>
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

const int N = 1e7 + 5;
int a[N];
vector <int> prime;

void is_prime() {
	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	prime.pb(2);
	for (int i = 3; i < N; i++) {
		if (i % 2)
			a[i] = 1;
	}
	for (int i = 3; i < N; i++) {
		if (a[i]) {
			prime.pb(i);
			for (int j = i * i; j < N; j += 2 * i) {
				a[j] = 0;
			}
		}
	}
}

void solve() {
	// for (auto x : prime)
	// 	cout << x << " ";
	// cout << endl;
	int n; scanf("%lld", &n);
	int ans;
	int nby1 = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
	int nby2 = upper_bound(prime.begin(), prime.end(), n / 2) - prime.begin();
	ans = nby1 - nby2;
	printf("%lld\n", ans);

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

	is_prime();

	int t; scanf("%lld", &t); while (t--)
		solve();

	return 0;
}