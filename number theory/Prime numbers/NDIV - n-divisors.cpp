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

const int N = 32000;
int is_prime[N];
vi prime;

void sieve() {
	REP(i, 2, N) {
		if (!is_prime[i]) {
			for (int j = i * i; j < N; j += i) {
				is_prime[j] = 1;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i < N; i += 2) {
		if (!is_prime[i])
			prime.pb(i);
	}
}

void solve() {

	int a, b, n; cin >> a >> b >> n;
	int ans = 0;
	int divisor = 1;
	bool flag = true;
	REP(i, a, b) {
		int temp = i;
		divisor = 1;
		for (auto x : prime) {
			if (x * x > temp)
				break;
			
			int cnt = 0;
			while (temp % x == 0) {
				temp /= x;
				cnt++;
			}
			//cout << cnt << endl;
			divisor = divisor * (cnt + 1);
		}
		if (temp > 1)
			divisor *= 2;
		if (divisor == n)
			ans++;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}