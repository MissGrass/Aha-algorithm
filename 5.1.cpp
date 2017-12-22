#include<stdio.h>
int book[101],sum,n,e[101][101];
void dfs(int cur)//cur is the top of the number
{
	int i;
	printf("%d ",cur);
	sum++;
	if(sum==n) return ;
	for(i=1;i<=n;i++) 
	{
		if(e[cur][i]==1 && book[i]==0)
		{
			book[i]=1;//sign i has been gone
			dfs(i);//continue 
		}
	}
	return ;
 } 
 
 int main()
 {
 	int i,j,m,a,b;
 	scanf("%d %d",&n,&m);
 	//initialize two-dimensional matrix
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;//999999999 as plus infinity
			
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//����������ͼ��������Ҫ��e[b][a]Ҳ��Ϊ1 
	 } 
	 
	//��1�Ŷ������
	book[1]=1;//���1�Ŷ����ѷ���
	dfs(1);//��1�Ŷ��㿪ʼ����
	
	getchar();getchar();
	return 0; 
 }
