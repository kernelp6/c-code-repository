#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k,a,b;
		cin>>n>>k>>a>>b;
		vector<vector<ll>> d(k+1,vector<ll>(n,-1));
		vector<ll> jz(n);
		for(ll i=0;i<n;i++){
			cin>>jz[i];
		} 
		d[0][0]=jz[0];
		ll mm=0;
		for(ll i=1;i<=k;i++){
			for(ll j=0;j<n;j++){
				for(ll l=a;l<=b;l++){
				if(j-l>=0&& d[i-1][j-l] != -1)
				d[i][j]=max(d[i-1][j-l]+jz[j],d[i][j]);
				if(mm<d[i][j]) {
					mm=d[i][j];
				}
				}
			}
		}
		cout<<mm<<endl;	
		
	}
	
	

}

	










