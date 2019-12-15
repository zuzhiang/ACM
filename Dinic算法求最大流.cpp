//https://comzyh.com/blog/archives/568/
/*
Dinic算法求从一源点到一汇点的最大流 

思路:
    1.用BFS建立分层图  注意:分层图是以当前图为基础建立的,
	  所以要重复建立分层图
    2.用DFS的方法寻找一条由源点到汇点的路径,获得这条路径
	  的流量I 根据这条路径修改整个图,将所经之处正向边流量
	  减少I,反向边流量增加I,注意I是非负数
    3.重复步骤2,直到DFS找不到新的路径时,重复步骤1
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 205
using namespace std;

int n,m;
int dis[MAX],map[MAX][MAX]; //dis[i]为源点到i经过的边数（层次） 

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int bfs(int root)
{ //用bfs建立分层网络，在分层网络中增广，无论怎么走都是最短路 
	int i,u;
	queue<int> Q;
	memset(dis,-1,sizeof(dis));
	dis[root]=0;
	Q.push(root);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
			if(dis[i]<0&&map[u][i]>0)
			{ //如果未处理过且与当前点相连 
				dis[i]=dis[u]+1; //层次+1 
				Q.push(i);
			}
	}
	if(dis[n]>0) return 1;
	else return 0;
}

int find(int u,int mi)
{ //从源点开始利用dfs从前一层向后一层反复寻找增广路 
	int i,sum=0;
	if(u==n) return mi;
	for(i=1;i<=n;i++)
		if(map[u][i]&&     //连通 
		dis[i]==dis[u]+1&& //是分层图的下一层 
		(sum=find(i,min(mi,map[u][i]))) //能到汇点
		{
			map[u][i]-=sum;
			map[i][u]+=sum;
			return sum;
		}
	return 0;
}

int main()
{
	int i,j,u,v,w,tmp,ans;
	while(~scanf("%d%d",&n,&m))
	{ //点数和边数 
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{ //两点及其边权 
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w; //可能不止一条边 
		}
		ans=0;
		while(bfs(1))
		{
			//一次bfs要不断的找增广路，直到找不到为止 
			while(tmp=find(1,INF)) ans+=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
