#include<iostream>

using namespace std;

int main()
{
	int a[1001],n,i,t;
	for(i=1;i<=1000;i++)
		a[i]=0;//初始化
		
	cin >> n;//读入n
	for(i=1;i<=n;i++)//循环读入n个图书的ISBN号 
	{
		cin >> t;//把每一个ISBN号读到变量t中
		a[t]=1;//标记出现过的isbn号 
	}
	
	for(i=1;i<=1000;i++)//依次判断1~1000这个1000个桶
	{
		if(a[i]==1)//如果ISBN号出现过则打印出来
			cout << i << " " ; 
	}
	
	getchar();getchar();
	return 0;
	 
 } 
