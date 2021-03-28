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

	int ans = n;
	cout << ans << endl;
	fflush(stdout);

	char inp;
	cin >> inp;

	int flag = 0;

	if (inp == 'E')
		return ;
	else if (inp == 'L')
		flag = 1;
	else
		flag = 2;

	if (flag == 1) {
		int start = 0, end = n;
		while (1) {
			cout << ans << endl;
			fflush(stdout);
			cin >> inp;
			cout << ans << endl;
			fflush(stdout);
			cin >> inp;
			if (inp == 'E') {
				break;
			}
			else if (inp == 'G') {
				start = ans;
				ans = (start + end) / 2;
			}
			else {
				end = ans;
				ans = (start + end) / 2;
			}
		}
	}
	else {
		int start = 0, end = n;
		while (1) {
			cout << ans << endl;
			fflush(stdout);
			cin >> inp;
			if (inp == 'E')
				break;
			else if (inp == 'G') {
				start = ans;
				ans = (start + end) / 2;
			}
			else {
				end = ans;
				ans = (start + end) / 2;
			}
			cout << ans << endl;
			fflush(stdout);
			cin >> inp;
		}
	}
	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}