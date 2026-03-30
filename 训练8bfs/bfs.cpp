#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> d;
vector<int> vis;
void dfs(int a,vector<int> &cr){
	vis[a]=1;
	cr.push_back(a);
	for(auto b:d[a]){
		if(!vis[b]){
			dfs(b,cr);
		}
	}
}
void bfs(int a,vector<int> &cr){
	queue<int> dl;
	dl.push(a);
	vis[a]=1;
	cr.push_back(a);
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
	}
	
	
}
signed main(){
	int n,m;
	cin>>n>>m;
	vis.resize(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		d[a].insert(b);
		d[b].insert(a);
	}
	
	vector<vector<int>> dcr;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vector<int> cr;
			dfs(i,cr);
			dcr.push_back(cr);
		}
	}
	for(auto a:dcr){
		cout<<"{ ";
		for(auto b:a){
			cout<<b<<" ";
		}
		cout<<"}"<<endl;
	}
	
	dcr.clear();
	vis.assign(n,0);
	
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vector<int> cr;
			bfs(i,cr);
			dcr.push_back(cr);
		}
	}
	
	for(auto b:dcr){
		cout<<"{ ";
		for(auto e:b){
			cout<<e<<" ";
		}
		cout<<"}"<<endl;
	}
	 
} 
