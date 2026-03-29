#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> d;
ll ff(ll a){
	
	if(a==d[a]) return a;
	else return d[a]=ff(d[a]);
	
}


int main(){
	ll n,m;
	ll t=0;
	while(cin>>n>>m){
		t++;
		if(!n&&!m){
			break;
		}
	d.assign(n+1,0);
	for(ll i=0;i<=n;i++){
		d[i]=i;
	}
	for(ll i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		ll fx=ff(a);
		ll fy=ff(b);
		if(fx!=fy){
			d[fx]=fy;
		}

	}
	
	ll con=0; 
	for(ll i=1;i<=n;i++){
		if(d[i]==i){
			con++;
		}
	}
		cout<<"Case "<<t<<": "<<con<<endl;
	}
	
	
	
} 









