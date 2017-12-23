#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int dis[10], bak[10], i, k, n, m, u[10], v[10], w[10], check, flag;
	int inf = 99999999;//用inf(infinity的缩写）存储一个我们认为的正无穷值
	//读入边
	for(i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
		
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for(i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;
	
	//Bellman-Ford算法核心语句
	for(k = 1; k <= n-1; k++) {
		check = 0;//用来标记在本轮松弛中数组dis是否会发生更新
		//进行一轮松弛
		for(i = 1; i <= m; i++) {
			if( dis[v[i]] > dis[u[i]] + w[i] ) {
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;//数组dis发生更新，改变check的值 
			}
		} 
		//松弛完毕后检测数组dis是否有更新
		if(check == 0) 
			break;//如果数组dis没有更新，提前退出循环结束算法 
	} 
	//检测负权回路
	flag = 0;
	for(i = 1; i <= m; i++)
		if( dis[v[i]] > dis[u[i]] + w[i] )
			flag = 1;
			
	if(flag == 1)
		printf("此图含有负权回路");
	else {
		//输出最终的结果
		for(i = 1; i <= n; i++)
			printf("%d ",dis[i]); 
	} 
	getchar();getchar();
	return 0;
}

