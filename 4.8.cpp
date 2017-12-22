#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y)
{
	//defined a directional array
	int next[4][2]={{0,1},//turn right
					{1,0},//go down
					{0,-1},//turn left
					{-1,0}};//go up
	int k,tx,ty;
	
	//enum four directions
	for(k=0;k<=3;k++)
	{
		//compute the coodinate of the next step
		tx=x+next[k][0];
		ty=y+next[k][1];
		//judge if it is over the boundary
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//judge if it is land
		if(a[tx][ty]>0 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty]=1;//sign the point has been gone
			dfs(tx,ty);//start to try next point 
		 } 
	 } 
	return ;
 } 
 
 
 int main()
 {
 	int i,j,startx,starty;
 	scanf("%d %d %d %d",&n,&m,&startx,&starty);
 	//read in the map
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	book[startx][starty]=1;
	sum=1;
	//start from land point
	dfs(startx,starty);
	printf("%d\n",sum);
	getchar();getchar();
	return 0; 
 }
