#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

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

const int N = 1e5 + 5;
int freq[N], a[N];
int ans[N];
const int blk = 317;

#define node pair<P,P>
node query[N];

bool comp(node a, node b) {
	if (a.F.F / blk != b.F.F / blk)
		return a.F.F / blk < b.F.F / blk;
	return a.F.S < b.F.S;
}

set <int> index;
int x;

void add(int pos) {
	freq[a[pos]]++;
	int cnt = freq[a[pos]];

	if (cnt == x) {
		index.insert(a[pos]);
	}
	if (cnt > x) {
		index.erase(a[pos]);
	}
	if (cnt < x) {
		index.erase(a[pos]);
	}
}

void del(int pos) {
	freq[a[pos]]--;
	int cnt = freq[a[pos]];

	if (cnt == x) {
		index.insert(a[pos]);
	}
	if (cnt > x) {
		index.erase(a[pos]);
	}
	if (cnt < x) {
		index.erase(a[pos]);
	}
}

void solve() {

	fill(a, a + N, 0);

	int n; cin >> n;
	REP(i, 0, n - 1)
	cin >> a[i];

	fill(freq, freq + N, 0);
	fill(ans, ans + N, -1);
	index.clear();

	int q; cin >> q;
	REP(i, 0, q - 1) {
		int l, r, xx; cin >> l >> r >> xx;
		query[i] = {{l, r}, {xx, i}};
	}

	sort(query, query + q, comp);

	int ml = 0, mr = -1;

	REP(i, 0, q - 1) {
		int l = query[i].F.F;
		int r = query[i].F.S;
		x = query[i].S.F;
		int ind = query[i].S.S;

		//cout << l << " " << r << endl;

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

		if (sz(index) >= 1)
			ans[ind] = *index.begin();
		else
			ans[ind] = -1;
		index.clear();
	}
	REP(i, 0, q - 1)
	cout << ans[i] << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t; while (t--)
		solve();

	return 0;
}