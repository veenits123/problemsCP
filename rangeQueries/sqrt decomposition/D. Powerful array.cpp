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

const int N = 2e5 + 5;
int a[N];
int freq[N];
int cnt = 0;
const int blk = 500;

#define seg pair<P,int>

bool comp(seg a, seg b) {
	if (a.F.F / blk != b.F.F / blk) {
		return a.F.F / blk < b.F.F / blk;
	}
	return (a.F.F / blk % 2) ? a.F.S < b.F.S: a.F.S>b.F.S;
}

void add(int pos) {
	int power = freq[a[pos]];
	freq[a[pos]]++;

	cnt -= (power * power) * a[pos];
	power++;
	cnt += (power * power) * a[pos];
}

void del(int pos) {
	int power = freq[a[pos]];
	freq[a[pos]]--;

	cnt -= (power * power) * a[pos];
	power--;
	cnt += (power * power) * a[pos];
}

void solve() {

	int n, q; cin >> n >> q;

	seg query[q + 2];
	int ans[q + 2];

	REP(i, 0, n - 1)
	cin >> a[i];

	REP(i, 0, q - 1) {
		int l, r; cin >> l >> r;
		l--, r--;

		query[i] = {{l, r}, i};
	}
	sort(query, query + q, comp);

	int ml = 0, mr = -1;

	REP(i, 0, q - 1) {
		int l = query[i].F.F;
		int r = query[i].F.S;
		int ind = query[i].S;

		//cout << l << " " << r << " " << ind << endl;

		while (l > ml) {
			del(ml);
			ml++;
		}
		while (ml > l) {
			ml--;
			add(ml);
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
	REP(i, 0, q - 1)
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