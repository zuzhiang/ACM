//https://comzyh.com/blog/archives/568/
/*
Dinic�㷨���һԴ�㵽һ��������� 

˼·:
    1.��BFS�����ֲ�ͼ  ע��:�ֲ�ͼ���Ե�ǰͼΪ����������,
	  ����Ҫ�ظ������ֲ�ͼ
    2.��DFS�ķ���Ѱ��һ����Դ�㵽����·��,�������·��
	  ������I ��������·���޸�����ͼ,������֮�����������
	  ����I,�������������I,ע��I�ǷǸ���
    3.�ظ�����2,ֱ��DFS�Ҳ����µ�·��ʱ,�ظ�����1
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 205
using namespace std;

int n,m;
int dis[MAX],map[MAX][MAX]; //dis[i]ΪԴ�㵽i�����ı�������Σ� 

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int bfs(int root)
{ //��bfs�����ֲ����磬�ڷֲ����������㣬������ô�߶������· 
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
			{ //���δ��������뵱ǰ������ 
				dis[i]=dis[u]+1; //���+1 
				Q.push(i);
			}
	}
	if(dis[n]>0) return 1;
	else return 0;
}

int find(int u,int mi)
{ //��Դ�㿪ʼ����dfs��ǰһ�����һ�㷴��Ѱ������· 
	int i,sum=0;
	if(u==n) return mi;
	for(i=1;i<=n;i++)
		if(map[u][i]&&     //��ͨ 
		dis[i]==dis[u]+1&& //�Ƿֲ�ͼ����һ�� 
		(sum=find(i,min(mi,map[u][i]))) //�ܵ����
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
	{ //�����ͱ��� 
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++)
		{ //���㼰���Ȩ 
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w; //���ܲ�ֹһ���� 
		}
		ans=0;
		while(bfs(1))
		{
			//һ��bfsҪ���ϵ�������·��ֱ���Ҳ���Ϊֹ 
			while(tmp=find(1,INF)) ans+=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
