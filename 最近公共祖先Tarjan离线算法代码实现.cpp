//http://www.cnblogs.com/JVxie/p/4854719.html
/*
Tarjan������������Ⱥ��������� 
Ϊ�����㷨�����������ͳһ����
ԭ��:
     1.������uΪ����Ԫ�صļ��ϡ� 
	 2.������u�����Ľڵ�v�����û�з��ʹ������vʹ��Tarjan�㷨��
	   �����󣬽�v�ļ��ϲ���u�ļ��ϡ� 
	 3.������u�йص�ѯ��(u,v) �����v�����ʹ�����������v����
	   ���ϵĴ���Ԫ�ء� 
*/
//������Ϊ���������̾��룬������������ȵı��� 
#include<stdio.h>
#include<string.h>
#define MAX 10005

int id,iq;  //�ֱ��¼�洢�ĵ��ѯ�ʵĸ��� 
int f[MAX],vis[MAX],dis[MAX]; //dis[i]��¼���ڵ㵽i�ľ��� 
//head[i]��¼��iΪ���ĵ�һ���ߵ��±꣬qhead���� 
int head[MAX],qhead[MAX];

struct node
{ //ǰ���� 
	int w;      //�����Ȩֵ 
	int to;     //�յ� 
	int next;   //��to�����ͬ����һ���ߵĴ洢�±� 
} edge[MAX],que[MAX];

void add_edge(int u,int v,int w) 
{ //�ӵ� 
	edge[id].to=v;
	edge[id].w=w;
	edge[id].next=head[u];
	head[u]=id++;
}

void add_que(int u,int v)
{ //��ѯ�� 
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
	memset(head,-1,sizeof(head));    //head��ʼ��Ϊ-1����ʾ����һ���� 
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
	{ //���������Ե�ǰ����Ϊ���Ľڵ� 
		if(!vis[edge[i].to])
		{
			//���ڵ㵽�յ�ľ���=���ڵ㵽���ľ��� + ��Ȩ 
			dis[edge[i].to]=dis[root]+edge[i].w;
			Tarjan(edge[i].to);
			f[edge[i].to]=root;
		}
	}
	for(i=qhead[root];i!=-1;i=que[i].next)
	{ //��ѯ�͵�ǰ�ڵ��йص�ѯ�� 
		if(vis[que[i].to])
		{
			//��������Ϊ���㵽���ڵ�ľ���� - ����������ܹ����ȵ����ڵ���� 
			que[i].w=dis[root]+dis[que[i].to]-2*dis[find(que[i].to)];
			que[i^1].w=que[i].w;  //��i��i+1�Ľ����ͬ��iΪż���� 
		}
	}	
}

int main()
{
	int i,t,n,m,k,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m); //�������ͱ��� 
		init(n);
		id=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w); //���ڵ㼰��֮���Ȩֵ 
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		scanf("%d",&k);  //ѯ���� 
		iq=0;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&u,&v);
			add_que(u,v);
		}
		Tarjan(1); //ѡ�ڵ�1��Ϊ���ڵ�
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
