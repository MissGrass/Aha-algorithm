#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;//����һ��ָ��p
	p=(int *)malloc(sizeof(int));//ָ��P��ȡ��̬������ڴ�ռ��ַ
	*p=10;//��ָ��p��ָ����ڴ�ռ��д���10
	printf("%d",*p);//���ָ��p��ָ����ڴ��е�ֵ
	
	getchar();getchar();
	return 0; 
}
