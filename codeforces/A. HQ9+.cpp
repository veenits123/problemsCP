#include <iostream>
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
	bool ans = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			ans = true;
			break;
		}
	}
	if (ans)
		cout << "YES";
	else
		cout << "NO";
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