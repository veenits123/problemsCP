#include <iostream>
#include <algorithm>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int32_t main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    // code starts

    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int kitna = 0, c = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i + 1] <= a[i]) {
                c++;
                kitna = max(kitna, c);
                temp = kitna;
            }
            if (a[i] < a[i + 1]) {
                kitna = temp;
                c = 0;
            }
        }
        if (kitna == 0) cout << 1 << endl;
        else cout << kitna << endl;
    }


    return 0;
}