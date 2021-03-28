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
	int n, q; cin >> n >> q;
	int a[n + 1], h[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int u, v; cin >> u >> v;
			h[u] = v;
		}
		else {
			int u, v; cin >> u >> v;
			int ans = h[u];
			bool flag = false;
			if (u >= v) {
				for (int i = u; i <= v; i++) {
					

				}

				if (flag) {
					cout << ans << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
			else{
				for(int i=u;i>=v;i--){
					for(int j=u-1;j>=v;j--){
						if(a[i]>a[j]){
							ans+=h[i];
							flag=true;
						}
					}
				}
			}
			if(flag){
				cout<<ans<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
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