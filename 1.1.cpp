#include<iostream>

int main()
{
	using namespace std;
	int book[1001],i,j,t,n;
	for(i=0;i<=1000;i++)
		book[i]=0;
	scanf("%d",&n);//����һ����n����ʾ��������n����
	for(i=1;i<=n;i++)
	{
		cin >> t;//��ÿһ������������t��
		book[t]++;//���м������Ա��Ϊt��Ͱ��һ��С���� 
	 } 
	for(i=1000;i>=0;i--)
		for(j=1;j<=book[i];j++)
			cout << i <<" ";
			
	getchar();getchar();
	return 0; 
}
