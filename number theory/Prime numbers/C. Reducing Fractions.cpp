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

const int N = 1e7 + 5;

int prime[N];
int fac_a[N], fac_b[N];

void sieve() {
	for (int i = 2; i < N; i++) {
		if (!prime[i])
			for (int j = i; j < N; j += i) {
				prime[j] = i;
			}
	}
}

void process(int a[], int n, int fac[]) {
	REP(i, 1, n) {
		for (int x = a[i]; x > 1; x /= prime[x]) {
			while (fac[prime[x]] > 0 && (a[i] % prime[x] == 0)) {
				fac[prime[x]]--;
				a[i] /= prime[x];
			}
		}
		cout << a[i] << " ";
	}
}

void solve() {

	int n, m; cin >> n >> m;
	int a[n + 1], b[m + 1];

	REP(i, 1, n) {
		cin >> a[i];
		for (int x = a[i]; x > 1; x /= prime[x]) {
			fac_a[prime[x]]++;
		}
	}
	REP(i, 1, m) {
		cin >> b[i];
		for (int x = b[i]; x > 1; x /= prime[x]) {
			fac_b[prime[x]]++;
		}
	}
	REP(i, 1, N) {
		int x = min(fac_a[i], fac_b[i]);
		fac_a[i] = fac_b[i] = x;
	}

	cout << n << " " << m << endl;

	process(a, n, fac_a);
	cout << endl;
	
	process(b, m, fac_b);

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