#include<stdio.h>

struct note
{
	int x;//abscissa
	int y;//ordinate
 } ;
 int main()
 {
 	struct note que[2501];
 	int head,tail;
 	int a[51][51];
 	int book[51][51]={0};
 	int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;
 	//defined a directional array
 	int next[4][2]={{0,1},//turn right
	 				{1,0},//go down
					{0,-1},//turn left
					{-1,0}};//go up
	//read in n row m rank and xiaoheng's coordinate
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//read in map
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
			
	//queue initializetion
	head=1;
	tail=1;
	//insert land coordinate in queue
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	sum=1;
	
	//while head<tail move
	while(head<tail)
	{
		//enum four directions
		for(k=0;k<=3;k++)
		{
			//compute coordinate of next step
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			//judge if it  is over the boundary;
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			
			//judge if the land ever go past
			if(a[tx][ty]>0 && book[tx][ty]==0)
			{ 
				sum++;
				//every point only enqueue ont time
				book[tx][ty]=1;
				//enqueue the new point
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
			 } 
		}
		head++;//this is important
	}
	//output the size of islands
	printf("%d\n",sum);
	
	getchar();getchar();
	return 0;
 }
