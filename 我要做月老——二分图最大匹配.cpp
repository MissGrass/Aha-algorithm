#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int e[101][101];
int match[101];
int book[101];
int n, m;
int dfs(int u) {
	int i;
	for(i = 1; i <= n; i++) {
		if(book[i] == 0 && e[u][i] == 1) {
			book[i] = 1;//��ǵ�i�ѷ��ʹ�
			//�����iδ����Ի����ҵ����µ����
			if( match[i] == 0 || dfs(match[i]) ) {
				//������Թ�ϵ
				match[i] = u;
				match[u] = i;
				return 1; 
			} 
		}
	}
	return 0;
}
int main() {
	int i, j, t1, t2, sum = 0;
	
	scanf("%d %d",&n, &m);//n����m����
	
	for(i = 1; i <= m; i++){//�����
		scanf("%d%d",&t1, &t2);
		e[t1][t2] = 1;
		e[t2][t1] = 1;//����������ͼ 
	} 
	
	for(i = 1; i <= n; i++)
		match[i] = 0;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++)
			book[j] = 0;//����ϴ�����ʱ�ı��
		if(dfs(i))
			sum++;//Ѱ������·������ҵ����������1 
	} 
	
	printf("%d",sum);
	
	getchar();getchar(); 
	return 0;
}

