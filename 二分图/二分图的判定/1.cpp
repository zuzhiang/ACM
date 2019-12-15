//无向图G为二分图的充分必要条件是，G至少有两个顶点，且其所有回路的长度均为偶数。
#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;

int col[1000],g[1000][1000];
//col数组是涂色数组，值为0和1 代表两种不同颜色，g[i][j] 记录i和j节点之间有边 

int bfs(int s,int n)
{
	int i,u;
	queue<int> Q;
	Q.push(s);
	col[s]=1;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
		{
			if(col[i]==-1 && g[u][i])
			{ //当前顶点没涂色，并且与u联通
				col[i]=!col[u]; //涂成和u节点相反的颜色 
				Q.push(i);
			}
			if(g[u][i] && col[i]==col[u]) return 0; //如果已经涂色的点与u连通且颜色相同则不是二分图
		}
	}
	return 1;
}

int main()
{
	int i,n,m,u,v,flag; //n为顶点个数,m为边的个数,点的编号从1~n
	scanf("%d %d",&n,&m);
	memset(col,-1,sizeof(col)); //将每个顶点的颜色涂为-1，代表没有涂色 
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //输入边的两个端点
		g[u][v]=g[v][u]=1;
	}
	flag=1;
	for(i=1;i<=n;i++)
		if(col[i]==-1 && !bfs(i,n))
		{ //如果该顶点没有涂色，则对其所在的连通分支进行bfs涂色，如果不是二分图则标志退出
			flag=0;
			break;
		}
	if(!flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}
