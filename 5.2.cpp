#include<stdio.h>
int main()
{
	int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
	int que[10001],head,tail;
	scanf("%d %d",&n,&m);
	//initialize two-dimensional matrix
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j)	e[i][j]=0;
			else 	e[i][j]=99999999;//999999999 as plus infinity
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//这里是无向图，所以需要将e[b][a]也赋值为1 
	 } 
	 
	//queue initialization
	head=1;
	tail=1;
	
	//从1号顶点出发，将1号顶点加入队列
	que[tail]=1;
	tail++;
	book[1]=1;//sign 1 号
	
	while(head<tail && tail<=n)
	{
		cur=que[head];//当前正在访问的顶点编号
		for(i=1;i<=n;i++)//从1~n依次尝试 
		{
			if(e[cur][i]=1 && book[i]==0)
			{
				//如果从顶点cur到顶点i有边，并且顶点i没有被访问过，则将顶点i入队
				que[tail]=i;
				tail++;
				book[i]=1;//标记顶点i已访问 
			 } 
			 
			//如果tail大于n，则表明所以顶点都已经被访问过
			if(tail>n)
			{
				break;
			 } 
		 } 
		head++;//注意这地方，千万不要忘记当一个顶点扩展结束后，head++，然后才能继续往下扩展 
	 } 
	 
	 
	 for(i=1;i<tail;i++)
	 	printf("%d ",que[i]);
	getchar();getchar();
	return 0; 
}
