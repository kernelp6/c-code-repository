#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	vector<string> d(2);
	cin>>d[0]>>d[1];
	ll con=0;
	ll n=d[0].size();
	for(ll i=0;i<n;i++){
		if(d[0][i]!=d[1][i]){
			ll flag=1;
			if(d[0][i]=='#') flag=0;
			else flag=1;
			
			if(d[flag][i+1]=='.'){
				ll j=i+1;
				while(j<n){
					 if(d[1][j]=='#'||d[0][j]=='#'){
						if(d[flag][j]=='#'){
							con+=j-i-1;
							break;
						}else{
							con+=j-i;
							d[flag][j]='#';
							break;
						}
					}
					j++;
				}
				i=j-1;
			}
			
		}else if(d[0][i]==d[1][i]&&d[0][i]=='#'&&d[0][i+1]=='.'&&d[1][i+1]=='.'){
			ll j=i+1;
			while(j<n){
				if(d[0][j]=='#'||d[1][j]=='#'){
					con+=j-i-1;
					break;
				}
				j++;
			}
			i=j-1;
		}
		
	}
	cout<<con;
	
	
}


 
