#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int h[101];//������Ŷѵ�����
int n; //�����洢����Ԫ�صĸ�����Ҳ���ǶѵĴ�С

//���������������������е�����Ԫ�ص�ֵ
void swap(int x, int y) {
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
} 

//���µ�������
void siftdown(int i) {//����һ����Ҫ���µ����Ľ����i�����ﴫ��1,���ӶѵĶ��㿪ʼ���µ���
	int t, flag = 0;//flag��������Ƿ���Ҫ�������µ���
	//��i����ж��ӣ���ʵ������������ӣ���������Ҫ����������ʱ��ѭ����ִ��
	while( i * 2 <= n && flag == 0 ) {
		//�����ж���������ӵĹ�ϵ������t��¼ֵ�ϴ�Ľ����
		if( h[i] < h[i * 2])
			t = i * 2;
		else
			t = i;
		//��������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
		if(i * 2 + 1 <= n) {
			//����Ҷ��ӵ�ֵ���󣬸��½�С�Ľ����
			if(h[t] < h[i * 2 + 1])
				t = i * 2 + 1; 
		} 
		//����������Ľ���Ų����Լ���˵���ӽ�����бȸ��ڵ�����
		if(t != i) {
			swap(t,i);//�������ǣ�ע��swap������Ҫ�Լ���д
			i = t;//����iΪ�ղ����������Ķ��ӽ��ı�ţ����ڽ������������µ��� 
		} 
		else
			flag = 1;//����˵����ǰ�ĸ�����Ѿ��������ӽ�㶼Ҫ���ˣ�����Ҫ�ٽ��е����� 
	} 
	return; 
} 

//�����ѵĺ���
void creat() {
	int i;
	//�����һ����Ҷ��㵽��1��������ν������ϵ���
	for(i = n/2; i >= 1; i--) {
		siftdown(i);
	} 
	return;
} 

//������
void heapsort() {
	while(n > 1) {
		swap(1,n);
		n--;
		siftdown(1);
	}
	return;
} 

int main() {
	int i, num;
	//����n����
	scanf("%d",&num);
	
	for(i = 1; i <= num; i++)
		scanf("%d",&h[i]);
	n = num;
	
	//����
	creat(); 
	
	//������
	heapsort();
	
	//���
	for( i = 1; i <= num; i++)
		printf("%d ", h[i]);
		
	getchar(); getchar();
	return 0;
}

