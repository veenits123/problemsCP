#include <iostream>
#include <vector>
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

const int N = 90e6 + 5;
vector <bool> is_prime(N, false);
vector <int> ans;

void sieve() {
	is_prime[2] = true;

	for (int i = 3; i <= N; i++) {
		if (i % 2)
			is_prime[i] = true;
	}
	//optimized by considering only odd nos. ;)

	for (int i = 3; i * i <= N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += 2 * i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (is_prime[i])
			ans.pb(i);
	}
}

void solve() {

	// for (auto x : ans)
	// 	cout << x << " ";

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		//cout << x << " ";
		cout << ans[x - 1] << endl;
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

	sieve();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}