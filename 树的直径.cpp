/*
��dfs������ֱ��������˵���ϵ��·
���н��ۣ�������һ��u�����ѵ�����Զ�ĵ�һ�����·��һ���˵㣬
Ȼ���ڴ�����㿪ʼ�ѣ��Ϳ����ѵ���һ���·�Ķ˵㣬
��������DFS�Ϳ����ҳ������· 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;

struct node
{
	int v,w; //�ߵĶ˵�ͳ��� 
};

int ans,pos,vis[10010]; //pos��¼��Զ��ı�ţ�vis��ʾ�Ƿ���ʹ� 
vector<node> t[10010]; //������ 

void dfs(int u,int dist)
{
	if(dist>ans)
	{ //�����ǰ�����ʼ���Զ 
		ans=dist;
		pos=u;
	}
	for(int i=0;i<t[u].size();i++)
	{ //���������� 
		node nd=t[u][i];
		if(!vis[nd.v])
		{ //���δ���ʹ� 
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
		{ //����n-1���� 
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
		dfs(1,0); //��һ�������ҵ�ֱ����һ���˵� 
		ans=0;
		memset(vis,0,sizeof(vis));
		vis[pos]=1;		
		dfs(pos,0); //�ڶ��������ҵ�ֱ������ 
		printf("ֱ������Ϊ��%d\n",ans);
	}
	return 0;
}
