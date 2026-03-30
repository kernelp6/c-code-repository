#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> d(2*n);
	ll c=0,j=0,i=0,f=0;

		
		while(i<n){
		if(!d[j]){
			c++;
		if(c==m){
			d[j]=1;
			c=0;
			i++;
			if(f) cout<<' ';
			cout<<j+1;
			f=1;
		}
		if(j<n-1) j++;
		else{
			j=0;
		}
		
		}else {
		if(j<n-1) j++;
		else{
			j=0;
		}	
		}	
		}	
		
	
	
} 














