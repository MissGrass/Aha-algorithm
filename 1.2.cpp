#include<stdio.h>

int main()
{
	int a[100],i,j,t,n;
	scanf("%d",&n);//输入一个数n，表示接下来有n个数
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//冒泡排序的核心部分
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	 } 
	for(i=1;i<=n;i++)//输出结果
		printf("%d ",a[i]);
		
	getchar();getchar();
	return 0; 
}
