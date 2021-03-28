#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b

using namespace std;



int phi(int n) 
{ 
    float result = n;
  
   
    for (int p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
                  while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (float)p)); 
        } 
    } 

    if (n > 1) 
        result *= (1.0 - (1.0 / (float)n)); 
  
    return (int)result; 
} 

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        int cnt = 0;
        cout << phi(n) << '\n';
    }

    return 0;
}
