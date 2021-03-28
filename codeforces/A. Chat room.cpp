#include <iostream>
#include <map>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	string s; cin >> s;
	string ans = "";
	map <char, int> m;
	m['h'] = 0, m['e'] = 0, m['l'] = 0, m['o'] = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'h' && !m['h'])
			ans += 'h', m['h']++;
		if (m['h'] && s[i] == 'e' && !m['e'])
			ans += 'e', m['e']++;
		if (m['e'] && s[i] == 'l' && m['l'] != 2)
			ans += 'l', m['l']++;
		if (m['l'] == 2 && s[i] == 'o' && !m['o'])
			ans += 'o', m['o']++;
	}
	if (ans == "hello")
		cout << "YES";
	else
		cout << "NO";
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