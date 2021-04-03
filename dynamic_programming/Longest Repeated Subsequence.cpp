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

string lrs(string s) {
	int n = sz(s);
	int dp[n + 1][n + 1];

	REP(i, 0, n)
	dp[i][0] = 0, dp[0][i] = 0;

	REP(i, 1, n) {
		REP(j, 1, n) {
			if (s[i - 1] == s[j - 1] && i != j) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans = "";
	int i = n, j = n;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j - 1] + 1)
			ans += s[i - 1], i--, j--;
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		else
			j--;
	}
	reverse(all(ans));
	return ans;
}

void solve() {

	string s; cin >> s;
	cout << lrs(s) << endl;

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