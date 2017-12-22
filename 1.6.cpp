#include<iostream>

using namespace std;

int main()
{
	int a[101],n,i,j,t;
	
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i];
	
	//开始冒泡排序
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	 } 
	cout << a[1] << " ";//输出第一个数
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])//如果当前这个数是第一次出现则输出
			cout << a[i] << " "; 
	 } 
	 
	 getchar();getchar();
	 return 0;
}
