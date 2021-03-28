#include<bits/stdc++.h>
using namespace std;

typedef long int ll;

void shift(ll *a, ll i1, ll i2, ll i3)
{
	ll temp = a[i3];
	a[i3] = a[i2];
	a[i2] = a[i1];
	a[i1] = temp;
}
int main()
{

	int test;
	cin>>test;
	while(test--)
	{
		ll n,k;
		cin>>n>>k;
		ll a[n],b[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			b[i] = a[i];	
		}
		sort(b,b+n);

		unordered_map<ll,ll>mp;
		for(ll i=0; i<n;i++)
			mp[b[i]] = i;
			

		ll result = 0;
		vector<pair<ll,pair<ll,ll>>> steps;
		ll pf=-1,ps=-1,i1,i2,i3;
		for(ll i=0; i<n; )
		{
			if(a[i]==b[i] || ps==i) 
			{
				i++;
				continue;
			}
			i1 = i;
			i2 = mp[a[i1]];
			i3 = mp[a[i2]];
			if(i3==i1 && pf==-1)
			{
				pf = i1;
				ps = i2;
				i++;
				continue;
			}
			else if(i3==i1)
			{
				i1 = pf;
				i2 = ps;
				i3 = i;
				pf=-1;
				ps=-1;
			}
			shift(a,i1,i2,i3);
			result++;
			steps.push_back({i1+1,{i2+1,i3+1}});
			if(a[i1]==b[i1])
				i++;

			if(result>k)
			{
				result = -1;
				break;
			}
		}

		if(pf!=-1)
		    result = -1;

		if(result<=k && result!=-1)
		{
			cout<<result<<"\n";
			for(auto &xx: steps)
				cout<<xx.first<<" "<<xx.second.first<<" "<<xx.second.second<<"\n";
		}
		else
			cout<<"-1\n";
	}

	return 0;
}