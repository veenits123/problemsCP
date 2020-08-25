#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int s, n; cin >> s >> n;
	vector <P> a;
	while (n--) {
		int x, y; cin >> x >> y;
		a.pb({x, y});
	}
	sort(a.begin(), a.end());
	bool ans = true;
	for (int i = 0; i < a.size(); i++) {
		if (s > a[i].F)
			s += a[i].S;
		else {
			ans = false;
			break;
		}
	}
	if (ans)
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