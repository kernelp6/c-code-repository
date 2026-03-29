#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct type{
	int zhi;
	type* l;
	type* r;
	type(int zhi=0,type* l=NULL,type* r=NULL):zhi(zhi),l(l),r(r){}
	
};
int a[31],b[31];
ll n;
ll t;
void bulttree(ll l,ll r,type* &root){
	ll flag=-1;
	for(ll i=l;i<=r;i++){
		if(a[t]==b[i]){
			flag=i;
			break;
		}
	}
	if(flag==-1){
		return ;
	}
	root = new type(a[t]);
	t--;
	if(flag<r) bulttree(flag+1,r,root->r);
	if(flag>l) bulttree(l,flag-1,root->l);
	
	
}
queue<type*> q;
ll e=0;
void cenbl(type* root){
	while(q.size()){
		
	type* f=q.front();
	q.pop();
	if(e) cout<<' ';
	cout<<f->zhi;
	e=1;
	if(f->l!=NULL) q.push(f->l);
	if(f->r!=NULL) q.push(f->r);	
	}
	
}
void shifang(type* root){
	queue<type*> q;
	q.push(root);
	while(q.size()){
		type* f=q.front();
		q.pop();
		if(f->l!=NULL) q.push(f->l);
		if(f->r!=NULL) q.push(f->r);
		delete f;
	}
}

int main(){
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for( ll i=1;i<=n;i++ ){
		cin>>b[i];
	}
	t=n;
	type* root;
	bulttree(1,n,root);
	q.push(root);
	cenbl(root);
//	shifang(root);
	
}








