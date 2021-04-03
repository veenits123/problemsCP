#include <iostream>
#include <set>
#include <array>
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

set <int> prime_factor(int n) {
	set <int> ans;
	for (auto x : {2, 3, 5}) {
		if (n % x == 0) {
			while (n % x == 0) {
				n /= x;
			}
			ans.insert(x);
		}
	}
	static array<int, 8> step = {4, 2, 4, 2, 4, 6, 2, 6};
	int p = 0;
	for (int i = 7; i * i <= n; i += step[p++]) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans.insert(i);
		}
		if (p == 8)
			p = 0;
	}
	if (n > 1)
		ans.insert(n);
	return ans;
}

void solve() {
	int n, m; cin >> n >> m;
	map <int, int> mark;
	while (m--) {
		char ch; int i; cin >> ch >> i;
		if (ch == '+') {
			set <int> s = prime_factor(i);
			if (!s.size())
				s.insert(1);
			bool flag = true, temp = false;
			for (auto x : s) {
				if (mark[x] && mark[x] != i) {
					flag = false;
					cout << "Conflict with " << mark[x] << endl;
					break;
				}
				if (mark[x] && mark[x] == i) {
					flag = false;
					cout << "Already on" << endl;
					break;
				}

			}
			if (flag) {
				for (auto x : s) {
					mark[x] = i;
				}
				cout << "Success" << endl;
			}
		}
		else {
			set<int> s = prime_factor(i);
			if (!s.size())
				s.insert(1);
			bool flag = false;
			for (auto x : s) {
				if (mark[x] == i) {
					mark[x] = 0;
					flag = true;
				}
			}
			if (flag) {
				cout << "Success" << endl;
			}
			if (!flag) {
				cout << "Already off" << endl;
			}
		}
	}

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