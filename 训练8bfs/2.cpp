#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
map<int,set<int>> d;
void bfs(int a,vector<int> &cr){
	queue<int> dl;
	dl.push(a);
	cr.push_back(a);
	vis[a]=1;
	int last=a,c=0;
	while(!dl.empty()){
		int f=dl.front();
		dl.pop();
		for(auto b:d[f]){
			if(!vis[b]){
			dl.push(b);
			vis[b]=1;
			cr.push_back(b);
			}
		}
		if(f==last){
		last=dl.back();
		c++;
		}
		if(c==6) return ;
	}
}

signed main(){
	int n,m;
	cin>>n>>m;
	vis.assign(n+1,0);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		d[a].insert(b);
		d[b].insert(a);
	}
	
	vector<double> dcr;
	for(int i=1;i<=n;i++){
		vector<int> cr;
		vis.assign(n+1,0);
		bfs(i,cr);
		double sum=cr.size()*100*1.0/n;
		dcr.push_back(sum);
	}
	
	
	for(int i=0;i<dcr.size();i++){
		cout<<i+1<<": "<<fixed<<setprecision(2)<<dcr[i]<<"%"<<endl;
	}
	
} 
