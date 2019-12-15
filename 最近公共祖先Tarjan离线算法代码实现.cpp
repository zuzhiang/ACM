//http://www.cnblogs.com/JVxie/p/4854719.html
/*
Tarjan求最近公共祖先和两点间距离 
为离线算法，先输入完后统一处理
原理:
     1.建立以u为代表元素的集合。 
	 2.遍历与u相连的节点v，如果没有访问过，则对v使用Tarjan算法，
	   结束后，将v的集合并入u的集合。 
	 3.对于与u有关的询问(u,v) ，如果v被访问过，则结果就是v所在
	   集合的代表元素。 
*/
//本代码为求两点间最短距离，是最近公共祖先的变形 
#include<stdio.h>
#include<string.h>
#define MAX 10005

int id,iq;  //分别记录存储的点和询问的个数 
int f[MAX],vis[MAX],dis[MAX]; //dis[i]记录根节点到i的距离 
//head[i]记录以i为起点的第一条边的下标，qhead类似 
int head[MAX],qhead[MAX];

struct node
{ //前向星 
	int w;      //两点间权值 
	int to;     //终点 
	int next;   //和to起点相同的下一条边的存储下标 
} edge[MAX],que[MAX];

void add_edge(int u,int v,int w) 
{ //加点 
	edge[id].to=v;
	edge[id].w=w;
	edge[id].next=head[u];
	head[u]=id++;
}

void add_que(int u,int v)
{ //加询问 
	que[iq].to=v;
	que[iq].next=qhead[u];
	qhead[u]=iq++;
	que[iq].to=u;
	que[iq].next=qhead[v];
	qhead[v]=iq++;
}

void init(int n)
{
	int i;
	for(i=0;i<=n;i++) f[i]=i;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(head,-1,sizeof(head));    //head初始化为-1，表示无下一条边 
	memset(qhead,-1,sizeof(qhead));
}

int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

void Tarjan(int root)
{
	int i;
	vis[root]=1;
	f[root]=root;
	for(i=head[root];i!=-1;i=edge[i].next)
	{ //不断搜索以当前顶点为起点的节点 
		if(!vis[edge[i].to])
		{
			//根节点到终点的距离=根节点到起点的距离 + 边权 
			dis[edge[i].to]=dis[root]+edge[i].w;
			Tarjan(edge[i].to);
			f[edge[i].to]=root;
		}
	}
	for(i=qhead[root];i!=-1;i=que[i].next)
	{ //查询和当前节点有关的询问 
		if(vis[que[i].to])
		{
			//两点间距离为两点到根节点的距离和 - 两倍的最近总共祖先到根节点距离 
			que[i].w=dis[root]+dis[que[i].to]-2*dis[find(que[i].to)];
			que[i^1].w=que[i].w;  //第i和i+1的结果相同（i为偶数） 
		}
	}	
}

int main()
{
	int i,t,n,m,k,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m); //顶点数和边数 
		init(n);
		id=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w); //两节点及其之间的权值 
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		scanf("%d",&k);  //询问数 
		iq=0;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&u,&v);
			add_que(u,v);
		}
		Tarjan(1); //选节点1作为根节点
		for(i=0;i<iq;i+=2) printf("%d\n",que[i].w);
	}
	return 0;
}
/*
1
7 6
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
3
1 6
1 4
2 6
*/
