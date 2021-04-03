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

const int N = 1e8;
vector <bool> is_prime(N, false);
vector <int> ans;

void sieve() {
	is_prime[2] = true;

	for (int i = 3; i <= N; i += 2) {
		is_prime[i] = true;
	}
	//optimized by considering only odd nos. ;)

	for (int i = 3; i * i <= N; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += 2 * i) {
				is_prime[j] = false;
			}
		}
	}
	ans.pb(2);
	for (int i = 3; i <= N; i += 2) {
		if (is_prime[i])
			ans.pb(i);
	}
}

void solve() {

	// for (auto x : ans)
	// 	cout << x << " ";

	for (int i = 1; i < ans.size(); i += 100) {
		if (ans[i] < 1e8)
			cout << ans[i - 1] << endl;
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