#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color)
{
	//defined a directional array
	int next[4][2]={{0,1},//turn right
					{1,0},//go dowm
					{0,-1},//turn left
					{-1,0}};//go up
	int k,tx,ty;
	a[x][y]=color;//dye a[x][y]
	//enum four directions
	for(k=0;k<=3;k++)
	{
		//the coordinate of next step
		tx=x+next[k][0];
		ty=y+next[k][1];
		//judge if it is over the boundary
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue ;
		//judge if it is land
		if(a[tx][ty]>0 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty]=1;//sign the point has been gone
			dfs(tx,ty,color);//start to try next point 
		 } 
	}
	return ;
}

int main()
{
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//read the map
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	book[startx][starty]=1;
	sum=1;
	//start to the  coordinate of the land
	dfs(startx,starty,-1);
	
	//output the dyed map
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%3d",a[i][j]); 
		}
		printf("\n");
	}
	getchar();getchar();
	return 0;	
			
}
