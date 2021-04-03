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

//O(n^2)
int lis(int a[], int n) {
	vi dp(n, 1);
	//vi res;
	//vi par(n, -1);

	REP(i, 1, n - 1) {
		REP(j, 0, i - 1) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				//par[i] = j;
			}
		}
	}
	//int pos = 0;
	// int mx = dp[0];
	// REP(i, 0, n - 1) {
	// 	if (mx < dp[i]) {
	// 		mx = dp[i];
	// 		//pos = i;
	// 	}
	// }
	// return mx;

	return *max_element(all(dp));
	// while (pos != -1) {
	// 	res.pb(a[pos]);
	// 	pos = par[pos];
	// }
	// reverse(all(res));

	// return res;
}

//O(nlogn)
// int lis(int a[], int n) {
// 	vector <int> res;
// 	res.push_back(a[0]);
// 	for (int i = 1; i < n; i++) {
// 		if (a[i] > res.back())
// 			res.push_back(a[i]);
// 		else {
// 			int x = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
// 			res[x] = a[i];
// 		}
// 	}
// 	return res.size();
// }

void solve() {

	int n; cin >> n;
	int a[n];
	REP(i, 0, n - 1)
	cin >> a[i];

	int ans = lis(a, n);
	cout << ans << endl;

	// cout << sz(ans) << endl;
	// for (int x : ans)
	// 	cout << x << " ";

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