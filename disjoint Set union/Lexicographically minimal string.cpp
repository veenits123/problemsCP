#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

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

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 2e2 + 5;
char par[N];

char find(char n) {
	return (par[n] == n) ? n : par[n] = find(par[n]);
}

void unite(char a, char b) {
	char x = find(a);
	char y = find(b);
	if (x != y) {
		if (y > x)
			par[y] = x;
		else
			par[x] = y;
	}
}

void solve() {

	string a, b, c;
	cin >> a >> b >> c;

	// REP(i, 0, 25) {
	// 	par[i] = i;
	// }
	for (char i = 'a'; i <= 'z'; i++) {
		par[i] = i;
	}
	REP(i, 0, a.size() - 1) {
		//int u = (int)(a[i] - 'a');
		//int v = (int)(b[i] - 'a');
		//unite(u, v);
		unite(a[i], b[i]);
	}

	string ans = "";
	// REP(i, 0, c.size() - 1) {
	// 	int x = find((int)(c[i] - 'a'));
	// 	for (int j = 0; j < 26; j++) {
	// 		if (x == find(j)) {
	// 			ans += (char)(j + 'a');
	// 			break;
	// 		}
	// 	}
	// }
	REP(i, 0, c.size() - 1) {
		ans += find(c[i]);
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}