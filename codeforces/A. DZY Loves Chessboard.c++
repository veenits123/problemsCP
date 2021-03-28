#include <iostream>
#include <vector>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n, m; cin >> n >> m;
	vector <string> a;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a.pb(s);
	}

	vector <string> ans;
	for (int i = 0; i < n; i++) {
		string x = "";
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				if ((i + j) & 1)
					x += 'B';
				else
					x += 'W';
			}
			else {
				x += '-';
			}
		}
		ans.pb(x);
	}
	for (auto x : ans)
		cout << x << endl;
	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--)
	solve();


	return 0;
}