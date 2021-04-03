#include <iostream>
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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;
	int freq[27] = {0};
	int c_freq[27] = {0};

	for (int i = 0; i < k; i++) {
		int x;
		char y;
		cin >> x >> y;
		freq[y - 'a'] = x;
	}

	int cnt = 0, ans = 1e18;
	int ptr = 0;

	for (int i = 0; i < n; i++) {
		c_freq[s[i] - 'a']++;

		if (c_freq[s[i] - 'a'] == freq[s[i] - 'a'])
			cnt++;
		//cout << cnt << endl;
		if (cnt == k) {//sara k tiles mil gyaa substring me ;)
			while (ptr < n && c_freq[s[ptr] - 'a'] > freq[s[ptr] - 'a']) {
				c_freq[s[ptr] - 'a']--;
				ptr++;
			}
			ans = min(ans, i - ptr + 1);
		}
	}
	if (ans != 1e18) {
		cout << ans;
		return ;
	}
	cout << "Andy rapopo";

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