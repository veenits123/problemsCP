#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <array>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e6 + 5;
vector <int> is_prime(N);
int ans[11][N];

void sieve() {
	//can't use sqrt(i) bcz a number can be multiple of more than one prime;
	//e.g. 6 has two factors {2,3} if we mark 6 with 2 only and run j from i*i
	// then 6 can't be encountered by 3 ;)
	//got it ??
	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) {
			//is_prime[i] = 1;//if using this then run j starting from 2*i;
			for (int j = i; j <= N; j += i) {
				is_prime[j]++;
			}
		}
	}
	for (int fac = 0; fac <= 10; fac++) {
		for (int i = 1; i <= N; i++) {
			ans[fac][i] = ans[fac][i - 1] + (is_prime[i] == fac);
		}
	}
}

void solve() {

	int a, b, n; cin >> a >> b >> n;
	cout << ans[n][b] - ans[n][a - 1] << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}