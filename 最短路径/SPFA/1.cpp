/*
SPFA算法为单源最短路算法，可处理负权边
原理：本质是BF算法的优化，只有那些在前一遍松弛中改变了
距离估计值的点,才可能引起他们的邻接点的距离估计值的改变。 
判断负权回路：记录每个结点进队次数,超过n次表示有负权。 

点的下标从1开始 
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

#define inf 0x3f3f3f3f

int dis[100]; //记录源点到该节点的距离
int vis[100]; //标志该节点是否在队列中
int num[100]; //记录该节点入队的次数
int mp[100][100]; //用邻接表存储顶点之间的距离

int SPFA(int v,int n)
{//参数：源点 / 点的个数 
	int i,q;
	//初始化dis数组
	for(i=0;i<=n;i++) dis[i]=inf;
	dis[v]=0;
    //初始化vis数组和num数组
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));	
	priority_queue<int,vector<int>,greater<int> > Q; //用优先队列进行优化
	Q.push(v); //将源点入队
	vis[v]=1;  //标志源点在队列中
	num[v]++;  //源点入队次数+1
	while(!Q.empty())
	{
		q=Q.top();
		Q.pop();
		vis[q]=0;  //标志队首元素q不在队列中
		for(i=1;i<=n;i++) //对和q节点相邻的节点进行扫描
			if(dis[q]+mp[q][i]<dis[i]) //如果源点到q节点的距离+q节点到i节点的距离<源点到i节点的距离
			{
				dis[i]=dis[q]+mp[q][i]; //进行松弛操作
				if(!vis[i])       //如果当前节点i不在队列中
				{
					Q.push(i);    //将当前节点i入队
					num[i]++;     //当前节点i入队次数+1
					vis[i]=1;     //标志在队列中
					if(num[i]>n) return 0;  //如果入队次数大于节点总个数，则说明存在负权回路
				}
			}
	}
	return 1;
}

int main()
{
	int i,j,n,m,u,v,w,flag;	
	while(~scanf("%d %d",&n,&m))  //顶点的个数和边的条数
	{
		//初始化mp数组
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mp[i][j]=inf;
		for(i=1;i<=n;i++)
			mp[i][i]=0;
	    //输入两顶点及它们的距离
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			mp[u][v]=w;   //若为无向图，则还需存储mp[v][u] 
		}
		flag=SPFA(1,n);  //SPFA操作
		//输出结果
		if(flag==0) printf("存在负权回路!\n");
		else
		{
			for(i=1;i<=n;i++)
				printf("%d ",dis[i]);
			printf("\n");
		}
	}
	return 0;
}

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
