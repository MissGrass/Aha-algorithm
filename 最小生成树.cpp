#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int n, m, i, j, k, min, t1, t2, t3;
	int e[7][7],dis[7],book[7]={0};//�����book��������˳�ʼ��
	int inf = 9999999;//��inf(infinity����д���洢һ��������Ϊ��������ֵ
	int cot = 0,sum = 0;//cot������¼�������ֶ���ĸ�����sum �����洢·��֮��
	//����n ��m,n��ʾ���������m��ʾ�ߵ�����
	scanf("%d %d",&n, &m);
	
	//��ʼ��
	for(i = 1; i <= n; i++) 
		for(j = 1; j <= n; j++)
			if(i == j) e[i][j] = 0;
			else e[i][j] = inf;
			
	//��ʼ�����
	for(i = 1; i <= m; i++) {
		scanf("%d %d %d",&t1,&t2,&t3);
		//ע������������ͼ��������Ҫ���߷����ٴ洢һ��
		e[t1][t2] = t3;
		e[t2][t1] = t3; 
	} 
	
	//��ʼ��dis���飬������1�Ŷ��㵽��������ĳ�ʼ���룬��Ϊ��ǰ��������ֻ��1�Ŷ���
	for(i = 1; i <= n; i++)
		dis[i] = e[1][i];
		
	//Prim���Ĳ��ֿ�ʼ
	//��1�Ŷ������������
	book[1] = 1;//������book�����һ�������Ƿ��Ѿ�����������
	cot++;
	while(cot < n) {
		min = inf;
		for(i = 1; i <= n; i++) {
			if(book[i] == 0 && dis[i] < min) {
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		cot++;
		sum = sum + dis[j];
		
		//ɨ�赱ǰ����j���еıߣ�����jΪ�м�㣬������������ÿһ����������ľ���
		for(k = 1; k <= n; k++) {
			if(book[k] == 0 && dis[k] > e[j][k])
				dis[k] = e[j][k];
		} 
	} 
	
	printf("%d",sum);//��ӡ���
	
	getchar(); getchar();
	return 0;
}

