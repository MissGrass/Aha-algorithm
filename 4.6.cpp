//���ѷ���ը���� 


#include<stdio.h>

char a[20][21];
int book[20][20],max,mx,my,n,m;
int getnum(int i,int j)
{
	int sum,x,y;
	sum=0;//sum��������
	
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#')//�жϵĵ��ǲ���ǽ���������ǽ�ͼ���
	{
		//�����ǰ�ĵ��ǵ��ˣ�����м���
		if(a[x][y]=='G')
			sum++;
		//x--�������Ǽ�������ͳ�� 
		x--;
	}  
	
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#')//�жϵĵ��ǲ���ǽ���������ǽ�ͼ���
	{
		//�����ǰ�ĵ��ǵ��ˣ�����м���
		if(a[x][y]=='G')
			sum++;
		//x++�������Ǽ�������ͳ�� 
		x++;
	 } 
	 
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#')//�жϵĵ��ǲ���ǽ���������ǽ�ͼ���
	{
		//�����ǰ�ĵ��ǵ��ˣ�����м���
		if(a[x][y]=='G')
			sum++;
		//y--�������Ǽ�������ͳ�� 
		y--;
	 } 
	 
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#')//�жϵĵ��ǲ���ǽ���������ǽ�ͼ���
	{
		//�����ǰ�ĵ��ǵ��ˣ�����м���
		if(a[x][y]=='G')
			sum++;
		//y++�������Ǽ�������ͳ�� 
		y++;
	 } 
	return sum;
}


void dfs(int x,int y)
{
	//����һ�����ڱ�ʾ�ߵķ��������
	int next[4][2]={{0,1},
					{1,0},
					{0,-1},
					{-1,0}}; 
	int k,sum,tx,ty;
	//���㵱ǰ������������ĵ�������
	sum=getnum(x,y);
	
	//����max��ֵ
	if(sum>max)
	{
		//�����ǰ�ĵ�ͳ�Ƴ�����������ĵ���������max,�����max,����mx��my��¼
		//��ǰ�������
		max=sum;
		mx=x;
		my=y; 
	 } 
	 
	//ö��4������
	for(k=0;k<=3;k++)
	{
		//��һ����������
		tx=x+next[k][0];
		ty=y+next[k][1];
		//�ж��Ƿ�Խ��
		if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
			continue;
		//�ж��Ƿ�Χǽ�����Ѿ��߹�
		if(a[tx][ty]=='.' && book[tx][ty]==0)
		{
			book[tx][ty]==1;//�����������߹�
			dfs(tx,ty);//��ʼ������һ���� 
		 } 
	 } 
	return ; 
}

int main()
{
	int i,startx,starty;
	
	//����n��m��n��m��
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//����n���ַ�
	for(i=0;i<=n-1;i++)
		scanf("%s",a[i]);
	
	//��С����վλ�ÿ�ʼ����
	book[startx][starty]=1;
	max=getnum(startx,starty);
	mx=startx;
	my=starty;
	dfs(startx,starty);
	
	printf("��ը�������ڣ�%d,%d��������������%d������\n",mx,my,max);
	
	getchar();getchar();
	return 0; 
}
