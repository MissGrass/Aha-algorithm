#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge {
	int u;
	int v;
	int w;
}; //Ϊ�˷����������ﴴ����һ���ṹ�������洢�ߵĹ�ϵ
struct edge e[10];//�����С����ʵ����������ã�Ҫ��m�����ֵ��1
int n, m;
int f[7] = {0}, sum = 0, cot = 0;//���鼯��Ҫ�õ���һЩ����
//f�����С����ʵ����������ã�Ҫ��n�����ֵ��1
void quicksort (int left, int right) {
	int i, j;
	struct  edge t;
	if(left > right)
		return;
	i = left;
	j = right;
	while(i != j) {
		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
		while(e[j].w >= e[left].w && i < j)
			j--;
		//�ٴ���߿�ʼ��
		while(e[i].w <= e[left].w && i < j)
			i++;
			
		//����
		if(i < j) {
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		} 
	}
	//���ս���׼����λ����left ��i����
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	
	quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i+1,right);//���������ұߵģ�������һ���ݹ�Ĺ���
	return; 
} 

//���鼯Ѱ�����ȵĺ���
int getf(int v) {
	if(f[v] == v)
		return v;
	else {
		//������·��ѹ��
		f[v] = getf(f[v]);
		return f[v]; 
	}
} 

//���鼯�ϲ����Ӽ��ϵĺ���
int merge(int v,int u) {
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if( t1 != t2 ) {//�ж��������Ƿ���ͬһ��������
		f[t2] = t1;
		return 1; 
	}
	return 0;
} 

 
int main() {
	int i;
	
	//����n��m,n��ʾ���������m��ʾ�ߵ�����
	scanf("%d %d",&n,&m);
	
	//����ߣ�������һ���ṹ�����洢�ߵĹ�ϵ
	for(i = 1; i <= m; i++)
		scanf("%d %d %d",&e[i].u, &e[i].v, &e[i].w);
	
	quicksort(1, m);//����Ȩֵ��С����Ա߽��п�������
	
	//���鼯��ʼ��
	for(i = 1; i <= n; i++)
		f[i] = i;
	//Kruskal�㷨���Ĳ���
	for(i = 1; i <= m; i++) {//��ʼ��С����ö��ÿһ����
		//�ж�һ���ߵ����������Ƿ��Ѿ���ͨ�����ж��Ƿ�����ͬһ��������
		if(merge(e[i].u,e[i].v)) {//���Ŀǰ��δ����ͨ����ѡ��������
			cot++;
			sum = sum + e[i].w; 
		} 
		if(cot == n-1)//ֱ��ѡ����n-1����֮���˳�ѭ��
			break; 
	} 
	
	printf("%d",sum);//��ӡ���
	
	getchar();getchar(); 
	return 0;
}

