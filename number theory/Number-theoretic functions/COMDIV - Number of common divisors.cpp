#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
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

const int N = 1e6 + 5;
int is_prime[N];
vi prime;

void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = 1;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i <= N; i += 2) {
		if (!is_prime[i])
			prime.pb(i);
	}
}

int no_of_divisor(int n) {
	vi fac;
	int cnt = 0;
	for (int x : prime) {
		if (x * x > n)
			break;
		if (n % x == 0) {
			cnt = 0;
			while (n % x == 0) {
				cnt++;
				n /= x;
			}
			cout << x << " " << cnt << endl;
			fac.pb(cnt);
		}
	}
	if (n > 1) {
		cout << n << " " << 1 << endl;
		fac.pb(1);
	}
	int ans = 1;
	for (auto x : fac) {
		//cout << x << " ";
		ans *= (x + 1);
	}
	return ans;
}

void solve() {

	// int a, b; cin >> a >> b;
	// int gcd = __gcd(a, b);
	// cout << no_of_divisor(gcd) << endl;
	no_of_divisor(200);

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