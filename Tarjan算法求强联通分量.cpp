//http://blog.csdn.net/acmmmm/article/details/16361033
//https://www.cnblogs.com/tgycoder/p/5048898.html
/*
连接的两个点无父子关系的边为横叉边，横叉边一定不产生环。
连接的两个点有父子关系的边为后向边，环一定由后向边产生
强连通分量是由若干环组成的 
强连通分量一定是DFS的一颗搜索树
强连通分量并缩点的作用是将杂乱无章的有向图变为有向无环图
*/
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

#define MAXN 100

int n,m;
//dfn记录节点的被访问时间（时间戳）
//low记录该点或者以这个点为根的子树能够追溯到最早的栈中节点的次序
int dfn[MAXN],low[MAXN];
//vis标记是否在栈中，num为每个强连通分量的节点数，belong标记节点属于第几个强连通分量
int vis[MAXN],num[MAXN],belong[MAXN]; 
int cnt,index; //cnt为强连通分量的个数，index为节点访问的编号（每个节点不同） 
stack<int> s;
vector<int> map[MAXN];

void tarjan(int u)
{ 
	int i,v;
 	dfn[u]=low[u]=++index; //新点初始化 
	s.push(u); //入栈 
	vis[u]=1;  //标记在栈中 
	for(i=0;i<map[u].size();i++)
	{ //处理与u相邻的节点 
		v=map[u][i];
		if(!dfn[v])
		{ //如果没被访问过,不能用!vis[v]，vis表示是否在栈中 
			tarjan(v); //递归处理 
			if(low[v]<low[u]) low[u]=low[v]; //将强连通分量的所有节点low值改为根节点的dfn值 
		}
		//如果访问过，并且在栈中，表明存在环
		else if(vis[v]&&dfn[v]<low[u]) low[u]=dfn[v];	
	}
	if(dfn[u]==low[u])
	{ //如果是强连通分量子树的最小根，此时栈内u之上的元素构成起一个强连通分量 
		cnt++; //第cnt个强连通分量 
		printf("连通分量 %d:",cnt);
		while(u!=v)
		{ //输出 也可以开个vector数组存储一下 
			v=s.top();
			printf(" %d",v);
			s.pop();
			vis[v]=0; //标记不在栈中 
			belong[v]=cnt; //节点v属于第cnt个强连通分量 
			num[cnt]++;
		}
		printf("\n");
	}
}

void solve()
{
	int i;
	cnt=0;
	index=0;
	memset(dfn,0,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	for(i=1;i<=n;i++) //如果没被访问过则从该点开始处理，防止有点遗漏 
		if(!dfn[i]) tarjan(i);
}

vector<int> mp[MAXN];   //由所有强连通分量形成的新图 
int chu[MAXN],ru[MAXN]; //出度和入度 

void suodian(int n)
{ //缩点函数，其中n为节点个数 
	int i,j,u,v;
	memset(chu,0,sizeof(chu));
	memset(ru,0,sizeof(ru));
	for(i=1;i<=n;i++)
	{ //扫描每个节点 
		u=belong[i];   //原来起点所在的强连通分量 
		for(j=0;j<map[i].size();j++)
		{ //每个节点的相邻节点 
			v=belong[map[i][j]]; //原来终点所在的强连通分量 
			if(u!=v)
			{ //如果不在同一强连通分量内 
				mp[u].push_back(v); //形成新图 
				chu[u]++;
				ru[v]++;
			}
		}		
	}
}

int main()
{
	int i,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			map[u].push_back(v);
		}
		solve();
		for(i=1;i<=n;i++) printf("%d ",belong[i]);
		printf("\n");
		suodian(n); //缩点 
	}
	return 0;
}
/*
6 8
1 3
1 2
2 4
3 5
3 4
4 1
4 6
5 6
*/
