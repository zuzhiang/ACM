/*
dijkstra算法为单源最短路径算法，不可处理负权
原理:将节点分为两组，处理完的和未处理的。开始时只有当前节点已处理，
不断的从未处理的节点中选择一个与当前节点的路径最短的，加入到已处理
节点中。然后用这个节点去更新未处理节点的路径。不断重复这个过程，直到
节点全部处理完。 
*/
#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f

int n,m;
int dis[101],vis[101],mp[101][101];

int dijkstra(int v) 
{
	int i,j,min,pos;
	memset(vis,0,sizeof(vis)); //全标记为未处理	
	for(i=1;i<=n;i++)  //dis[i]表示当前节点与i的路径长度，初始化为最大 
		dis[i]=mp[v][i];
    dis[v]=0;
	vis[v]=1;
	//算法核心代码
	for(i=1;i<n;i++)
	{ //进行n-1次处理 
		min=inf;
		for(j=1;j<=n;j++) //寻找未处理的点中路径最短的 
			if(!vis[j] && dis[j]<min)
			{
				min=dis[j];
				pos=j;
			}
		vis[pos]=1;
		for(j=1;j<=n;j++) //用该节点更新其他未处理节点的最短路径 
			if(!vis[j]&&dis[j]>dis[pos]+mp[pos][j])
					dis[j]=dis[pos]+mp[pos][j];			
	}
}

int main()
{
	int i,j,u,v,w;
	scanf("%d %d",&n,&m);
	//初始化mp数组 
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			mp[i][j]=inf;
	for(i=1;i<=n;i++)
		mp[i][i]=0;
	for(i=0;i<m;i++)
	{ //读入u、v两点之间的距离w 
		scanf("%d %d %d",&u,&v,&w);
		mp[u][v]=w;
	}    
	dijkstra(1);
    //输出
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	printf("\n");
	return 0;
}

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
