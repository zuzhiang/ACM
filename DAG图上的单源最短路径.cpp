/*
DAG�ϵĵ�Դ���·���㷨��ʱ�临�Ӷ�O(m) 
��0��Ϊ����Դ��
˼·���ȶ�DAG������������Ȼ���������
���������·�� 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define MAXN 1010
#define MAXM 5010
#define inf 0x3f3f3f3f
using namespace std;

int tol,head[MAXN];      //��ʽǰ���� 
int n,m,cnt,dgr[MAXN];   //dgr��¼������ 
int dis[MAXN],que[MAXN]; //dis��¼�㵽Դ�����̾��룬que��¼������������ 
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
	Q.push(0); //0�����
	for(i=1;i<=n;i++) dis[i]=inf; //��ʼ����̾��� 
	while(!Q.empty())
	{ //ֻ�м��ߵĵ���п������Ϊ0 
		top=Q.front();
		Q.pop();
		que[cnt++]=top;  //������������ 
		dgr[top]--;      //��ǰ�ڵ����-1 
		for(i=head[top];i!=-1;i=edge[i].next)
		{ //������top�����Ľڵ� 
			dgr[edge[i].to]--; //���-1 
			if(dgr[edge[i].to]==0) Q.push(edge[i].to); //������Ϊ0����� 
		}
	}
}

void solve()
{
	int i,j,v;
	for(i=0;i<cnt;i++) //�����������д��� 
		for(j=head[que[i]];j!=-1;j=edge[j].next)
		{ //����i�����ڽڵ� 
			v=edge[j].to;
			if(dis[v]>dis[que[i]]+edge[j].w) //���¾��� 
				dis[v]=dis[que[i]]+edge[j].w;
		}
	for(i=1;i<=n;i++) printf("%d ",dis[i]);
	printf("\n");
}

int main()
{
	int i,u,v,w;
	while(~scanf("%d%d",&n,&m))
	{ //�����ͱ��� 
		init();
		for(i=0;i<m;i++)
		{ //�������㼰����� 
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			dgr[v]++;
		}
		for(i=1;i<=n;i++)
			if(dgr[i]==0)
			{ //��0�����Ϊ0�ĵ�֮��ӱ� 
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
