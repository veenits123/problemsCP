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

vector <P> constant;

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
			constant.pb({x, cnt});
		}
	}
	if (num > 1) {
		constant.pb({num, 1});
	}
}

void solve() {

	// for (auto x : constant)
	// 	cout << x.F << " " << x.S << endl;
	// cout << endl;

	int q; cin >> q;
	while (q--) {

		int k; cin >> k;
		vector <P> temp;
		REP(i, 0, constant.size() - 1) {
			int cnt = constant[i].S;
			int no = constant[i].F;
			if (k % no == 0) {
				int c = 0;
				while (k % no == 0) {
					c++;
					k /= no;
				}
				temp.pb({no, min(c, cnt)});
			}
			else {
				temp.pb({no, 0});
			}
		}
		for (auto x : temp)
			cout << x.F << " " << x.S << endl;
		cout << endl;
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

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}