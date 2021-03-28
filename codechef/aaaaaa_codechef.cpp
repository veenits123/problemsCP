#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

bool compare(string a, string b) {
	return (a + b < b + a);
}

string lexSmallest(vector<string> a, int n) {
	sort(a.begin(), a.end(), compare);
	string ans = "";
	for (int i = 0; i < n; i++)
		ans += a[i];
	return ans;
}

string getString(char x) {
	string s(1, x);

	return s;
}

void solve() {
	string s; cin >> s;
	string p; cin >> p;

	map <char, int> m;
	for (int i = 0; i < s.size(); i++) {
		m[s[i]]++;
	}
	for (int i = 0; i < p.size(); i++) {
		if (m[p[i]])
			m[p[i]]--;
	}

	vector <string> a;
	a.pb(p);
	for (auto x : m) {
		while (x.S) {
			char temp = x.F;
			a.pb(getString(temp));
			x.S--;
		}
	}
	int n = a.size();
	//int n = sizeof(a) / sizeof(a[0]);
	cout << lexSmallest(a,n) << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}