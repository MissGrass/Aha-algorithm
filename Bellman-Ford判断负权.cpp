#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int dis[10], bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;//��inf(infinity����д���洢һ��������Ϊ��������ֵ
	//�����
	for(i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
		
	//��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ·��
	for(i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;
	
	//Bellman-Ford�㷨�������
	for(k = 1; k <= n-1; k++) {
		check = 0;//��������ڱ����ɳ�������dis�Ƿ�ᷢ������
		//����һ���ɳ�
		for(i = 1; i <= m; i++) {
			if( dis[v[i]] > dis[u[i]] + w[i] ) {
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;//����dis�������£��ı�check��ֵ 
			}
		} 
		//�ɳ���Ϻ�������dis�Ƿ��и���
		if(check == 0) 
			break;//�������disû�и��£���ǰ�˳�ѭ�������㷨 
	} 
	//��⸺Ȩ��·
	flag = 0;
	for(i = 1; i <= m; i++)
		if( dis[v[i]] > dis[u[i]] + w[i] )
			flag = 1;
			
	if(flag == 1)
		printf("��ͼ���и�Ȩ��·");
	else {
		//������յĽ��
		for(i = 1; i <= n; i++)
			printf("%d ",dis[i]); 
	} 
	getchar();getchar();
	return 0;
}

