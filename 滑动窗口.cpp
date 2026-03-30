#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> vis(m+1),d(n+1);
	for(ll i=1;i<=n;i++)
	{
		cin>>d[i];	
	}	
	pair<ll,ll> memo={1,n};
	ll i=1,j=1,c=0;
	while(j<=n||c==m)
	{
		
		while(c<m&&j<=n)
		{
			if(vis[d[j]]==0) c++;
			vis[d[j]]++;
			if(c!=m) j++;
			
		}
		if(c==m)
		{
			if(j-i<memo.second-memo.first) memo={i,j}; 
			vis[d[i]]--;
			if(vis[d[i]]==0) {
				c--;
				j++;
			}
			i++;
		}
		
		
	} 
	
	
	cout<<memo.first<<' '<<memo.second;
}
