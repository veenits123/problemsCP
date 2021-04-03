#include <iostream>
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
int is_prime[N];

void sieve() {
	for (int i = 0; i < N; i++)
		is_prime[i] = 1;
	is_prime[0] = 0;
	is_prime[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = 0;
			}
		}
	}
}

void solve() {
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (is_prime[i])
			ans++;
	cout << ans << endl;

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