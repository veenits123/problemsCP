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
int prefix[N];

void solve() {
	int a, b, c, d; cin >> a >> b >> c >> d;

	for (int i = a; i <= b; i++) {
		prefix[i + b] += 1;
		prefix[i + c + 1] -= 1;
	}

	for (int i = 1; i <= N; i++) {
		prefix[i + 1] += prefix[i];
	}
	for (int i = 1; i <= N; i++) {
		prefix[i + 1] += prefix[i];
	}

	int ans = 0;
	for (int i = c; i <= d; i++) {
		ans += prefix[N] - prefix[i];
	}
	cout << ans;


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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}