#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ll n,k;
	cin>>n>>k;
	map<ll,ll> zhi;
	vector<ll> d(n);
	for(ll i=0;i<n;i++){
		cin>>d[i];
		ll b=k^d[i];
		zhi[d[i]]=zhi[b]+1;
		
		
	} 
	ll ma=1;
	for(auto it:zhi){
		if(ma<it.second){
			ma=it.second;
		}
	}
	cout<<ma;
	
}
