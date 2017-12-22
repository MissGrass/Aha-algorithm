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
		e[b][a]=1;//这里是无向图，所以需要将e[b][a]也赋为1 
	 } 
	 
	//从1号顶点出发
	book[1]=1;//标记1号顶点已访问
	dfs(1);//从1号顶点开始遍历
	
	getchar();getchar();
	return 0; 
 }
