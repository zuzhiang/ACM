/*
DAG上的单源最短路径算法，时间复杂度O(m) 
以0点为超级源点
思路：先对DAG进行拓扑排序，然后根据拓扑
序列求最短路径 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define MAXN 1010
#define MAXM 5010
#define inf 0x3f3f3f3f
using namespace std;

int tol,head[MAXN];      //链式前向星 
int n,m,cnt,dgr[MAXN];   //dgr记录点的入度 
int dis[MAXN],que[MAXN]; //dis记录点到源点的最短距离，que记录拓扑排序序列 
queue<int> Q;

struct node
{
	int w,to,next;
} edge[MAXM];

void init()
{
	tol=0;
	memset(head,-1,sizeof(head));
	memset(dgr,0,sizeof(dgr));		
}

void add(int u,int v,int w)
{
	edge[tol].w=w;
	edge[tol].to=v;
	edge[tol].next=head[u];
	head[u]=tol++;
}

void tuopu()
{
	int i,top;
	cnt=0;	
	dis[0]=0;   
	Q.push(0); //0点入队
	for(i=1;i<=n;i++) dis[i]=inf; //初始化最短距离 
	while(!Q.empty())
	{ //只有减边的点才有可能入度为0 
		top=Q.front();
		Q.pop();
		que[cnt++]=top;  //保存拓扑序列 
		dgr[top]--;      //当前节点入度-1 
		for(i=head[top];i!=-1;i=edge[i].next)
		{ //遍历与top相连的节点 
			dgr[edge[i].to]--; //入度-1 
			if(dgr[edge[i].to]==0) Q.push(edge[i].to); //如果入度为0则入队 
		}
	}
}

void solve()
{
	int i,j,v;
	for(i=0;i<cnt;i++) //依照拓扑序列处理 
		for(j=head[que[i]];j!=-1;j=edge[j].next)
		{ //遍历i的相邻节点 
			v=edge[j].to;
			if(dis[v]>dis[que[i]]+edge[j].w) //更新距离 
				dis[v]=dis[que[i]]+edge[j].w;
		}
	for(i=1;i<=n;i++) printf("%d ",dis[i]);
	printf("\n");
}

int main()
{
	int i,u,v,w;
	while(~scanf("%d%d",&n,&m))
	{ //点数和边数 
		init();
		for(i=0;i<m;i++)
		{ //输入两点及其距离 
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			dgr[v]++;
		}
		for(i=1;i<=n;i++)
			if(dgr[i]==0)
			{ //在0和入度为0的点之间加边 
				add(0,i,0);
				dgr[i]++;
			}
		tuopu();
		solve();
	}
	return 0;
}
/*
8 9
1 2 1
1 6 3
2 3 2
2 4 2
3 5 3
4 5 3
6 7 4
5 8 0
7 8 0
*/
