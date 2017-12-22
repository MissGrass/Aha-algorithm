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
	int i,j,num=0;
	scanf("%d %d",&n,&m);
	//read the map
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	//dye every greater than zero point 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>0)
			{
				num--;
				book[i][j]=1;
				dfs(i,j,num);
			}
		}
	}
	
	//output the dyed map
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%3d",a[i][j]); 
		}
		printf("\n");
	}
	//output islands number
	printf("there is %d islands",-num);
	getchar();getchar();
	return 0;	
			
}
