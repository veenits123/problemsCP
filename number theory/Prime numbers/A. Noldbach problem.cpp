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

const int N = 1e3 + 5;
vector <bool> is_prime(N);
vector <int> prime;
vector <int> ans(N);
int res[N];

void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i <= N; i += 2)
		if (!is_prime[i])
			prime.pb(i);

	const int sz = prime.size();
	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = 0; j < sz - 1; j++) {
				if (i - 1 == (prime[j] + prime[j + 1])) {
					ans[i]++;
					break;
				}
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		res[i] = res[i - 1] + ans[i];
	}
}

void solve() {
	// for (auto x : res)
	// 	cout << x << " ";
	int n, k; cin >> n >> k;
	if (res[n] >= k)
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

	sieve();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}