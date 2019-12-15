/*
用dfs求树的直径，或者说树上的最长路
现有结论，从任意一点u出发搜到的最远的点一定是最长路的一个端点，
然后在从这个点开始搜，就可以搜到另一个最长路的端点，
即用两遍DFS就可以找出树的最长路 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;

struct node
{
	int v,w; //边的端点和长度 
};

int ans,pos,vis[10010]; //pos记录最远点的编号，vis表示是否访问过 
vector<node> t[10010]; //保存树 

void dfs(int u,int dist)
{
	if(dist>ans)
	{ //如果当前点离初始点更远 
		ans=dist;
		pos=u;
	}
	for(int i=0;i<t[u].size();i++)
	{ //遍历相连点 
		node nd=t[u][i];
		if(!vis[nd.v])
		{ //如果未访问过 
			vis[nd.v]=1;
			dfs(nd.v,dist+nd.w);
		}
	}
}

int main()
{
	node nd;
	int i,n,u,v,w;
	while(~scanf("%d",&n))
	{
		for(i=0;i<=n;i++) t[i].clear();
		for(i=0;i<n-1;i++)
		{ //输入n-1条边 
			scanf("%d%d%d",&u,&v,&w);
			nd.v=v;
			nd.w=w;
			t[u].push_back(nd);
			nd.v=u;
			t[v].push_back(nd);
		}
		ans=0;
		memset(vis,0,sizeof(vis));
		vis[1]=1;				
		dfs(1,0); //第一遍深搜找到直径的一个端点 
		ans=0;
		memset(vis,0,sizeof(vis));
		vis[pos]=1;		
		dfs(pos,0); //第二遍深搜找到直径长度 
		printf("直径长度为：%d\n",ans);
	}
	return 0;
}
