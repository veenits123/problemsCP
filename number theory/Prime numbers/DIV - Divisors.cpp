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

#define int long long int
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

void sieve() {
	for (int i = 2; i <= N; i += 2) {
		is_prime[i] = true;
	}
	for (int i = 3; i * i <= N; i += 2) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += 2 * i) {
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

vi divisor(N);
vi ans;

void calc() {
	REP(i, 2, N) {
		int temp = i;
		int d = 1;
		for (auto x : prime) {
			if (x * x > temp)
				break;
			int cnt = 0;
			while (temp % x == 0) {
				cnt++;
				temp /= x;
			}
			d *= (cnt + 1);
		}
		if (temp > 1) {
			d *= 2;
		}
		divisor[i] = d;
	}
	REP(i, 2, N) {
		int temp = divisor[i];
		int cnt = 0;
		vi flag;
		for (auto x : prime) {
			if (x * x > temp)
				break;
			cnt = 0;
			if (temp % x == 0) {
				while (temp % x == 0) {
					temp /= x;
				}
				//cnt++;
				flag.pb(x);
			}
		}
		if (temp > 1 && divisor[i] % temp == 0) {
			cnt++;
			flag.pb(temp);
		}
		if (flag.size() >= 2 && flag[0]*flag[1] == divisor[i])
			ans.pb(i);
		flag.clear();
	}
}

void solve() {

	// for (auto x : prime)
	// 	cout << x << " ";
	// REP(i, 1, N)
	// cout << divisor[i] << " ";
	// for (auto x : ans)
	// 	cout << x << " ";
	for (int i = 8; i < ans.size(); i += 9) {
		cout << ans[i] << endl;
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
	calc();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}