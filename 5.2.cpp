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
		e[b][a]=1;//����������ͼ��������Ҫ��e[b][a]Ҳ��ֵΪ1 
	 } 
	 
	//queue initialization
	head=1;
	tail=1;
	
	//��1�Ŷ����������1�Ŷ���������
	que[tail]=1;
	tail++;
	book[1]=1;//sign 1 ��
	
	while(head<tail && tail<=n)
	{
		cur=que[head];//��ǰ���ڷ��ʵĶ�����
		for(i=1;i<=n;i++)//��1~n���γ��� 
		{
			if(e[cur][i]=1 && book[i]==0)
			{
				//����Ӷ���cur������i�бߣ����Ҷ���iû�б����ʹ����򽫶���i���
				que[tail]=i;
				tail++;
				book[i]=1;//��Ƕ���i�ѷ��� 
			 } 
			 
			//���tail����n����������Զ��㶼�Ѿ������ʹ�
			if(tail>n)
			{
				break;
			 } 
		 } 
		head++;//ע����ط���ǧ��Ҫ���ǵ�һ��������չ������head++��Ȼ����ܼ���������չ 
	 } 
	 
	 
	 for(i=1;i<tail;i++)
	 	printf("%d ",que[i]);
	getchar();getchar();
	return 0; 
}
