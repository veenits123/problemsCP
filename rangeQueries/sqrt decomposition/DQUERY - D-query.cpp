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

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 3e4 + 5;
int a[N];
int freq[1000005];
int cnt;
const int blk = 200;

#define query pair<P,int>

bool comp(query a, query b) {
	if (a.F.F / blk != b.F.F / blk)
		return a.F.F / blk < b.F.F / blk;
	return a.F.S < b.F.S;
}

bool comp1(query a, query b) {
	if (a.F.F / blk != b.F.F / blk)
		return a.F.F / blk < b.F.F / blk;
	return (a.F.F / blk % 2) ? a.F.S < b.F.S : a.F.S > b.F.S;
}

void add(int pos) {
	freq[a[pos]]++;
	if (freq[a[pos]] == 1)
		cnt++;
}

void del(int pos) {
	freq[a[pos]]--;
	if (freq[a[pos]] == 0)
		cnt--;
}

void solve() {

	int n; cin >> n;
	REP(i, 0, n - 1)
	cin >> a[i];

	int qr; cin >> qr;
	query q[qr + 1];

	REP(i, 0, qr - 1) {
		int l, r; cin >> l >> r;
		l--, r--;
		q[i] = {{l, r}, i};
	}
	int ans[qr + 2];

	int ml = 0, mr = -1;

	sort(q, q + qr, comp1);

	REP(i, 0, qr - 1) {
		int l = q[i].F.F;
		int r = q[i].F.S;
		int ind = q[i].S;

		while (ml > l) {
			ml--;
			add(ml);
		}
		while (l > ml) {
			del(ml);
			ml++;
		}
		while (r > mr) {
			mr++;
			add(mr);
		}
		while (mr > r) {
			del(mr);
			mr--;
		}
		ans[ind] = cnt;
	}
	REP(i, 0, qr - 1)
	cout << ans[i] << endl;

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