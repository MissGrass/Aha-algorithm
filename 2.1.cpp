#include<iostream>

using namespace std;

int main()
{
	int q[102]={0,6,3,1,7,5,8,9,2,4},head,tail;
	//��ʼ������
	head=1;
	tail=10;//�������Ѿ���9��Ԫ���ˣ�tailָ���β�ĺ�һ��λ��
	while(head<tail)//�����в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		//��ӡ���ײ������׳���
		cout << q[head] << " ";
		head++;
		
		//�Ƚ��¶��׵�����ӵ���β
		q[tail]=q[head];
		tail++;
		//�ٽ����׳���
		head++; 
	 } 
	 
	 getchar();getchar();
	 return 0;
}
