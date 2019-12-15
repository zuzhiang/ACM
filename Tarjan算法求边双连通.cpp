//Tarjan算法求桥及所有的边双连通分量，判断两点之间是否有桥 
//该算法和Tarjan求强连通分量算法基本一样，只是多了v!=pre的判断 
/*
边双连通图的定义等价于任意一条边至少在一个简单环中
边双连通的极大子图称为边双连通分量
桥不在任何一个边双连通分量中
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#define MAXN 50010
#define MAXM 50010
using namespace std;

int n,m,cnt,index; //cnt边双的数量，index时间戳 
int vis[MAXN]; //记录点是否在栈中 
//dfn记录节点的被访问时间（时间戳）
//low记录该点或者以这个点为根的子树能够追溯到最早的栈中节点的次序
int dfn[MAXN],low[MAXN];
int belong[MAXN],bridge[MAXN]; //属于哪个边双，记录桥 
vector<int> mp[50010];
stack<int> st;

void init()
{
	int i;
	cnt=index=0;
	memset(dfn,-1,sizeof(dfn));
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;i++)
		mp[i].clear();		
}

void Tarjan(int u,int pre)
{
	int i,v;
	dfn[u]=low[u]=++index;
	st.push(u);
	vis[u]=1;
	for(i=0;i<mp[u].size();i++)
	{ //处理与u相邻的节点 
		v=mp[u][i];
		if(dfn[v]==-1)
		{ //如果没被访问过,不能用!vis[v]，vis表示是否在栈中
			Tarjan(v,u); //递归处理 
			if(low[v]<low[u]) low[u]=low[v]; //将强连通分量的所有节点low值改为根节点的dfn值			
		}		
		else if(vis[v]&&v!=pre)
		{ //如果访问过，并且在栈中，表明存在环
			if(dfn[v]<low[u]) low[u]=dfn[v];
		}
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		while(u!=v)
		{
			v=st.top();
			st.pop();
			vis[v]=0;
			belong[v]=cnt; //节点v属于第cnt个强连通分量
		}
	}
}

void solve()
{
	int i;
	for(i=1;i<=n;i++) //如果没被访问过则从该点开始处理，防止有点遗漏
		if(dfn[i]==-1) Tarjan(i,-1);
}

int main()
{
	int i,q,u,v;
	scanf("%d%d",&n,&m);	
	init();
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	solve();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&u,&v);
		if(belong[u]==belong[v]) printf("Yes\n"); //如果在同一边双中则无桥 
		else printf("No\n");
	}
	return 0;
}
