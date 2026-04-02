#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll a,b;
    cin>>a>>b;
    vector<ll> d(a);
    for(ll i=0;i<a;i++){
    	cin>>d[i];
	}
	sort(d.begin(),d.end());
	vector<ll> je(b+1,INT_MAX);
	je[0]=0;
	for(ll i=0;i<a;i++){
		for(ll j=d[i];j<=b;j++){
			if(je[j]>je[j-d[i]]+1)
			je[j]=je[j-d[i]]+1;
		}
	}
	cout<<je[b];
}
