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

const int N = 5e4 + 5;
int a[N], func[N];
int freq[1000005];
const int blk = 250;
int res;

#define node pair<P,int>

int binpow(int a, int n, int m = mod) {
	a = a % m;
	int ans = 1;
	while (n > 0) {
		if (n & 1)
			ans = ans * a % m;
		n >>= 1;
		a = a * a % m;
	}
	return ans % m;
}

int inverse(int a) {
	return binpow(a, mod - 2);
}

bool comp(node a, node b) {
	if (a.F.F / blk != b.F.F / blk)
		return a.F.F / blk < b.F.F / blk;
	return (a.F.F / blk % 2) ? a.F.S < b.F.S : a.F.S > b.F.S;
}

void add(int pos) {
	if (freq[a[pos]] >= 0)
		res = res * inverse(func[freq[a[pos]]]) % mod;

	freq[a[pos]]++;

	if (freq[a[pos]] >= 0)
		res = res * func[freq[a[pos]]] % mod;
}

void del(int pos) {
	if (freq[a[pos]] >= 0)
		res = res * inverse(func[freq[a[pos]]]) % mod;

	freq[a[pos]]--;

	if (freq[a[pos]] >= 0)
		res = res * func[freq[a[pos]]] % mod;
}

void solve() {

	int n, c, q; cin >> n >> c >> q;

	REP(i, 0, n - 1)
	cin >> a[i];

	REP(i, 0, n)
	cin >> func[i];

	node query[q + 2];

	REP(i, 0, q - 1) {
		int l, r; cin >> l >> r;
		l--, r--;

		query[i] = {{l, r}, i};
	}

	sort(query, query + q, comp);

	res = 1;
	REP(i, 1, c) {
		res = res * func[freq[i]] % mod;
	}

	int ml = 0, mr = -1;
	int ans = 1;

	REP(i, 0, q - 1) {
		int l = query[i].F.F;
		int r = query[i].F.S;
		int ind = query[i].S;

		while (l > ml) {
			del(ml);
			ml++;
		}
		while (l < ml) {
			ml--;
			add(ml);
		}
		while (r > mr) {
			mr++;
			add(mr);
		}
		while (r < mr) {
			del(mr);
			mr--;
		}

		ans = ans * res % mod;
	}
	cout << ans % mod;

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