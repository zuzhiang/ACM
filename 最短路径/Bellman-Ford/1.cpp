/*
BF最短路算法为单源最短路算法，可以解决负权问题
原理：对m条边进行n-1次松弛，第i次松弛的意思是源点v至多经过i
条边到达目标点的最短路 
*/
#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int n,m,dis[1000];

struct node
{ //记录点u、v之间的距离w 
	int u,v,w;
}a[1000];

int bf(int v)
{
	int i,j;
	for(i=0;i<=n;i++) dis[i]=inf;  //距离初始化为最大值 
	dis[v]=0;
	for(j=0;j<n-1;j++)  //进行n-1次
		for(i=0;i<m;i++)
		{
			//如果1经过u到v的距离小于1直接到v的距离则更新 
			if(dis[a[i].v]>dis[a[i].u]+a[i].w)
				dis[a[i].v]=dis[a[i].u]+a[i].w;
			//由于是对有向图而言，只需要上面这种方向的检测即可			
		}
	//如果已经松弛完后，扔存在dis[a[i].v]>dis[a[i].u]+a[i].w则存在回路 
	for(i=1;i<=m;i++)
		if(dis[a[i].v]>dis[a[i].u]+a[i].w)
			return 0;
	return 1;
}

int main()
{
	int i,j; //dis[i]表示节点1到节点i的距离 
	while(~scanf("%d%d",&n,&m))
	{ //n为节点数，m为边数 		
		for(i=0;i<m;i++)
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);	
		bf(1);
		for(i=1;i<=n;i++)
			printf("%d ",dis[i]);
		printf("\n");
	}
	return 0;
}
//PS: 下面的数据表示的为有向图 
/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3

5 5
2 3 2
2 1 -3
5 1 5
4 5 2
3 4 3
*/

