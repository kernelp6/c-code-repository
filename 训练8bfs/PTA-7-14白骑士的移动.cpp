#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//int read(){
//	ll f=1,x=0;
//	char c;
//	c=getchar();
//	while(c<'0'||c>'9'){
//		if(c=='-') f=-1;
//		c=getchar();
//	}
//	
//	while(c>='0'&&c<='9'){
//		x=x*10+c-'0';
//		c=getchar();
//	}	
//	
//	return x*f;			
//}
ll dis[8][8];
int n=8;
ll bs[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int main(){
	vector<vector<char>> d(8,vector<char>(8,'.'));
	ll c,g,e,h;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]=='K') {
			c=i;
			g=j;	
			}
			
			if(d[i][j]=='Q'){
			e=i;
			h=j;	
			}
		}
	}
	vector<vector<char>> Map(8,vector<char>(8,0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(d[i][j]=='R'){
				ll fl1=0,fl2=0,fl3=0,fl4=0;
				ll a=1;
				Map[i][j]=1;
				while(a!=8){
					if(!fl1&&i+a<=7&&d[i+a][j]=='.') Map[i+a][j]=1;
					else fl1=1;
					if(!fl2&&i-a>=0&&d[i-a][j]=='.') Map[i-a][j]=1;
					else fl2=1;
					if(!fl3&&j+a<=7&&d[i][j+a]=='.') Map[i][j+a]=1;
					else fl3=1;
					if(!fl4&&j-a>=0&&d[i][j-a]=='.') Map[i][j-a]=1;
					else fl4=1; 
					a++;
				}
			}else if(d[i][j]=='B') {
					ll a=1;
					ll fl1=0,fl2=0,fl3=0,fl4=0;
					Map[i][j]=1;
					while(a!=8){
						if(!fl1&&i+a<=7&&j+a<=7&&d[i+a][j+a]=='.') Map[i+a][j+a]=1;
						else fl1=1;
						if(!fl2&&i-a>=0&&j-a>=0&&d[i-a][j-a]=='.') Map[i-a][j-a]=1;
						else fl2=1;
						if(!fl3&&i+a<=7&&j-a>=0&&d[i+a][j-a]=='.') Map[i+a][j-a]=1;
						else fl3=1;
						if(!fl4&&i-a>=0&&j+a<=7&&d[i-a][j+a]=='.') Map[i-a][j+a]=1;
				    	else fl4=1;
				    	a++;
					}
					
				
			}
		
		}
		
	}
	vector<vector<ll>> vis(8,vector<ll>(8));
	vis[c][g]=1;
	queue<pair<ll,ll>> q;
	q.push({c,g});
	
	while(!q.empty()){
		pair<ll,ll> f=q.front();
		q.pop();
		for(ll i=0;i<8;i++){
		if(f.first+bs[i][0]>=0&&f.first+bs[i][0]<=7&&f.second+bs[i][1]>=0&&f.second+bs[i][1]<=7&&!vis[f.first+bs[i][0]][f.second+bs[i][1]]){
			if(Map[f.first+bs[i][0]][f.second+bs[i][1]]==0) {
			q.push({f.first+bs[i][0],f.second+bs[i][1]});
			vis[f.first+bs[i][0]][f.second+bs[i][1]]=1;	
			dis[f.first+bs[i][0]][f.second+bs[i][1]]=dis[f.first][f.second]+1;
			
			}
		}
		} 
	}
	if(dis[e][h]) cout<<dis[e][h];
	else cout<<"Checkmate";
	
	
} 













