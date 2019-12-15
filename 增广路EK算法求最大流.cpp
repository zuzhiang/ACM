//http://www.cnblogs.com/dchipnau/archive/2011/09/16/4985966.html
/*
EK�㷨�����һ��Դ�㵽һ����������� 
����·������һ����s��t��·��,·����ÿ���߲���������Ϊ��
˼�룺���ϵ���bfs������·������������·�����еı߶���ȥ������·�е���С
���� ��ͬʱ����߼�����С������ֱ���Ҳ���λ�ã��㷨�����������Ϊÿ����С
�����ĺ͡� 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define MAX 205
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
//pre[i]��¼i�ڵ��ǰһ�ڵ� 
int pre[MAX],map[MAX][MAX];

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int bfs(int start,int end)
{ //Ѱ������·������bfsѰ�����·����¼�ڵ��ǰ�� 
	int i,u;
	int vis[MAX];
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre)); //ǰ����ʼ��Ϊ-1 
	queue<int> Q;
	Q.push(start);
	vis[start]=1;
	while(!Q.empty())
	{
		u=Q.front();
		if(u==end) return 1; //�ҵ��򷵻� 
		Q.pop();
		for(i=1;i<=n;i++)
		{   //��������ұ�ȨΪ����δ���ʹ� 
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
		{ //�Ӻ󲻶���ǰ����ȷ����С���� 
			mi=min(mi,map[pre[u]][u]);
			u=pre[u];
		}
		sum+=mi;
		u=end;
		while(pre[u]!=-1)
		{  //����߼�ȥ��С���������߼�����С���� 
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
	{ //�����ͱ��� 
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{ //���㼰���Ȩ 
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w; //���ܲ�ֹһ���� 
		}
		ans=EK(1,n); //��1ΪԴ�㣬��nΪ������ 
		printf("%d\n",ans);
	}
	return 0;
}
