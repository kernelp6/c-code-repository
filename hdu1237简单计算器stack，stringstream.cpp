#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	while(true){
	stack<double> s;
	string a;
	getline(cin,a);
	if(a=="0") break;
	stringstream  ss(a);
	double b;
	char ch;
	ss>>b;
	s.push(b);
	while(ss>>ch>>b){
		if(ch=='+'){
			s.push(b);
		}else if(ch=='-'){
			s.push(-b);
		}else if(ch=='*'){
			double c=s.top();
			s.pop();
			s.push(c*b);
		}else if(ch=='/'){
			double c=s.top();
			s.pop();
			s.push(c/b);
		}
	}
	double sum=0;
	while(s.size()){
		sum+=s.top();
		s.pop();
	}
	printf("%.2f\n",sum);
	}
	
		
	
	
	
			
		
} 














