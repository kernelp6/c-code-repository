#include<bits/stdc++.h>
using namespace std;
int n,a[114514],p,l;//数组开大一点
string q;
void C()//乘法
{
	for(int i=1;i<=l;i++)
		a[i]*=2;//按位乘2
	for(int i=1;i<=l;i++)//进位
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;	
	}
	if(a[l+1])//如果最高位的前一位进位后不是0就要增加长度
		l++;
}
int main()
{
	cin>>n>>q;//q为输入的小数
	reverse(q.begin(),q.end());//反转q方便后续做题
	p=q.find(".");//p用来分割整数、小数部分
	q.erase(p,1);//把烦人的小数点删了
	l=q.size();//l为小数总长
	for(int i=0;i<l;i++)
		a[i+1]=q[i]-48;//字符串转整数数组
	for(int i=1;i<=n;i++)//n次乘2
		C();
	if(a[p]>=5)//小数部分第一位为5四舍五入进位
		a[p+1]++;	
	for(int i=p+1;i<=l;i++)//检查进位
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}	
	if(a[l+1])//再次检查最高位
   		l++;	
	for(int i=l;i>p;i--)//因为前面逆序了所以这里倒着输出
		cout<<a[i];
	return 0;
}

