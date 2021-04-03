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

const int N = 1e5 + 5;
vector <bool> is_prime(N);

void sieve() {

	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i])
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
	}
}

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		cout << 1 << endl;
		return ;
	}
	if (n == 2) {
		cout << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return ;
	}
	cout << 2 << endl;
	for (int i = 2; i <= n + 1; i++) {
		if (!is_prime[i])
			cout << "1" << " ";
		else
			cout << "2" << " ";
	}
	cout << endl;

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