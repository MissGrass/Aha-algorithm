#include<iostream>

using namespace std;

int main()
{
	int a[1001],n,i,t;
	for(i=1;i<=1000;i++)
		a[i]=0;//��ʼ��
		
	cin >> n;//����n
	for(i=1;i<=n;i++)//ѭ������n��ͼ���ISBN�� 
	{
		cin >> t;//��ÿһ��ISBN�Ŷ�������t��
		a[t]=1;//��ǳ��ֹ���isbn�� 
	}
	
	for(i=1;i<=1000;i++)//�����ж�1~1000���1000��Ͱ
	{
		if(a[i]==1)//���ISBN�ų��ֹ����ӡ����
			cout << i << " " ; 
	}
	
	getchar();getchar();
	return 0;
	 
 } 
