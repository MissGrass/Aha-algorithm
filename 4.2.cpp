#include<stdio.h>

int a[10],book[10],total=0;
void dfs(int step)//step表示现在站在第几个盒子面前
{
	int i;
	if(step==10)//表示前面9个盒子已经摆放好
	{
		//判读是否满足条件
		if(a[1]*100 + a[2]*10 + a[3] + a[4]*100 + a[5]*10 + a[6] == a[7]*100 + a[8]*10 + a[9]) 
		{
			//如果满足，可行解+1，并且打印这个解
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d	",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]); 
		 }
		return;//返回之前的一步(最近调用的地方） 
	 } 
	//此时站在第step个盒子面前，应该放哪张牌呢？
	//按照1/2/3……n的顺序一一尝试
	for(i=1;i<=9;i++)
	{
		//判读扑克牌i是否还在手上
		if(book[i]==0)//book[i]为0表示扑克牌还在手上
		{
			//开始尝试使用扑克牌i
			a[step]=i;//将扑克牌i放入到第step个盒子中
			book[i]=1;//表示扑克牌已经不在手中了
			//下一个盒子
			dfs(step+1);//递归调用
			book[i]=0;//收回刚刚尝试的扑克牌，再进行下一次尝试 
		 } 
	 } 
	return; 
 } 
 
 
int main()
{
	dfs(1);//首先站在第一个盒子面前
	
	printf("total=%d",total/2);//因为有重复所以除以二
	getchar(); getchar();
	return 0;
}
