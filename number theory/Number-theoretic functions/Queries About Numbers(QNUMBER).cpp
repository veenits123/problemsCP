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
vb is_prime(N);
vi prime;
int num;
map <int, int> constant;

void sieve() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = true;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i <= N; i += 2) {
		if (!is_prime[i])
			prime.pb(i);
	}
}

void prime_factorization() {
	for (auto x : prime) {
		if (x * x > num)
			break;
		if (num % x == 0) {
			int cnt = 0;
			while (num % x == 0) {
				num /= x;
				cnt++;
			}
			constant[x] = cnt;
		}
	}
	if (num > 1) {
		constant[num] = 1;
	}
}

int no_of_div_of_n;

void facn() {
	no_of_div_of_n = 1;
	for (auto x : constant) {
		no_of_div_of_n *= (x.S + 1);
	}
}

void solve() {

	int type, k; cin >> type >> k;
	if (type == 1) {
		int ans = 1;
		for (auto x : constant) {
			int cnt = 0;
			while (k % x.F == 0) {
				k /= x.F;
				cnt++;
			}
			ans *= min(cnt, x.S) + 1;
		}
		cout << ans << endl;
	}
	else {
		int ans = 1;
		for (auto x : constant) {
			int cnt = 0;
			while (k % x.F == 0) {
				k /= x.F;
				cnt++;
			}
			if (cnt > x.S) {//means power of prime 'x.F' is greater in 'k' than in 'num';
				ans = 0;
				break;
			}
			ans *= (x.S - cnt) + 1;
		}
		if (k > 1)//it means this prime is not present in 'num';
			ans = 0;
		if (type == 2)
			cout << ans << endl;
		else
			cout << no_of_div_of_n - ans << endl;
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

	cin >> num;
	sieve();
	prime_factorization();
	facn();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}