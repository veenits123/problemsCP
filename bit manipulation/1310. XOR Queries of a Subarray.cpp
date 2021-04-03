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

class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

		vector <int> pref(arr.size(),0);
		pref[0] = arr[0];

		for (int i = 1; i < arr.size(); i++)
			pref[i] = pref[i - 1] ^ arr[i];

		vector <int> ans;
		for (int i = 0; i < queries.size(); i++) {
			int l = queries[i][0];
			int r = queries[i][1];

			if (l > 0) {
				ans.push_back(pref[r] ^ pref[l - 1]);
			}
			else
				ans.push_back(pref[r]);
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;

	vi a(n);
	REP(i, 0, n - 1)
	cin >> a[i];

	int q; cin >> q;
	vector<vector<int>> qr(q);

	REP(i, 0, q - 1) {
		int l, r; cin >> l >> r;
		qr[i].pb(l);
		qr[i].pb(r);
	}
	vi ans = Solution().xorQueries(a, qr);

	for (int x : ans)
		cout << x << " ";

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