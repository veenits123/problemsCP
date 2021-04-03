#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 5e4 + 10;
vb is_prime(N);
vi prime;

void sieve() {
	REP(i, 2, N) {
		if (!is_prime[i])
			for (int j = i * i; j < N; j += i) {
				is_prime[j] = true;
			}
	}
	prime.pb(2);
	for (int i = 3; i < N; i += 2) {
		if (!is_prime[i])
			prime.pb(i);
	}
}

vector <P> fact[N];

void no_of_div() {
	REP(i, 2, N) {
		int temp = i;
		for (auto x : prime) {
			if (x * x > temp)
				break;
			int cnt = 0;
			while (temp % x == 0) {
				temp /= x;
				cnt++;
			}
			if (cnt)
				fact[i].pb({x, cnt});
		}
		if (temp > 1) {
			fact[i].pb({temp, 1});
		}
	}
}

int power_of_prime_factors[N];

void solve() {

	memset(power_of_prime_factors, 0, sizeof(power_of_prime_factors));

	int n; cin >> n;
	REP(i, 2, n) {
		for (auto x : fact[i]) {
			power_of_prime_factors[x.F] += x.S;
		}
	}
	
	int ans = 1;
	REP(i, 2, n) {
		ans = ans * 1LL * (power_of_prime_factors[i] + 1) % mod;
	}
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
	no_of_div();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}