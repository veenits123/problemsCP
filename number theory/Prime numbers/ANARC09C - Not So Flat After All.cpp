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

const int N = 1e5 + 5;

vector <P> factorize(int n) {
	vector <P> res;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			res.pb({i, cnt});
		}
	}
	if (n > 1) {
		res.pb({n, 1});
	}
	return res;
}

void solve() {

	int tc = 1;
	while (true) {
		int a, b; cin >> a >> b;
		if (a == 0 && b == 0)
			return ;

		vector <P> aa = factorize(a), bb = factorize(b);

		set <int> unite;
		map <int, int> aaa, bbb;

		for (auto x : aa) {
			unite.insert(x.F);
			aaa[x.F] = x.S;
		}
		for (auto x : bb) {
			unite.insert(x.F);
			bbb[x.F] = x.S;
		}

		int dis = 0;
		for (auto x : unite) {
			int p = aaa[x];
			int q = bbb[x];
			dis += abs(p - q);
		}

		cout << tc << ". " << sz(unite) << ":" << dis << endl;
		tc++;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}