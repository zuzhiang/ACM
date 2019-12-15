//http://www.cnblogs.com/dchipnau/archive/2011/09/16/4985966.html
/*
EK算法，求从一个源点到一个汇点的最大流 
增广路是这样一条从s到t的路径,路径上每条边残留容量都为正
思想：不断的用bfs找增广路，让这条增广路中所有的边都减去此增广路中的最小
流量 ，同时反向边加上最小流量。直到找不到位置，算法结束。最大流为每次最小
流量的和。 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define MAX 205
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
//pre[i]记录i节点的前一节点 
int pre[MAX],map[MAX][MAX];

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int bfs(int start,int end)
{ //寻找增广路，即用bfs寻找最短路并记录节点的前驱 
	int i,u;
	int vis[MAX];
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre)); //前驱初始化为-1 
	queue<int> Q;
	Q.push(start);
	vis[start]=1;
	while(!Q.empty())
	{
		u=Q.front();
		if(u==end) return 1; //找到则返回 
		Q.pop();
		for(i=1;i<=n;i++)
		{   //如果相邻且边权为正且未访问过 
			if(map[u][i]&&!vis[i])
			{
				pre[i]=u;
				Q.push(i);
				vis[i]=1;
			}
		}
	}
	return 0;
}

int EK(int start,int end)
{
	int u,mi,sum;
	sum=0; 
	while(bfs(start,end))
	{
		mi=INF;
		u=end;
		while(pre[u]!=-1)
		{ //从后不断找前驱，确定最小流量 
			mi=min(mi,map[pre[u]][u]);
			u=pre[u];
		}
		sum+=mi;
		u=end;
		while(pre[u]!=-1)
		{  //正向边减去最小流量，最大边加上最小流量 
			map[pre[u]][u]-=mi;
			map[u][pre[u]]+=mi;
			u=pre[u];
		}
	}
	return sum;
}

int main()
{
	int i,j,u,v,w,ans;
	while(~scanf("%d%d",&n,&m))
	{ //点数和边数 
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{ //两点及其边权 
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w; //可能不止一条边 
		}
		ans=EK(1,n); //以1为源点，以n为汇点查找 
		printf("%d\n",ans);
	}
	return 0;
}
