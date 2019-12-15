/*
������һ�����еı߹��ɵĻ�·Ϊŷ����·��
��һ��ͼ�����е����ȵĵ��ڳ��ȣ�����ŷ����·��

ŷ��·��ԭ�� 
һ�����ŷ��ͼɾȥһ�����һ��С��ŷ��ͼ����һ��ŷ��ͼ��
һ��ŷ��ͼ����ӽڵ�s��ʼ�����������Ҳһ����s����Ϊ���һ���ڵ�
�����-1���������Ҳһ��-1����s��ʼ����ֻ��s�ĳ���-1�����û�䡣
��ȫ���������ʱ�����е�ĳ���ȶ�Ϊ0���������һ����Ӧ��Ϊs��
���Դӽڵ�s��ʼ������һ�����γ�һ����s������Сŷ��ͼ������s��ǰ���ڵ�
�ͻ��γ�һ�������ŷ��ͼ��ֱ���γ�������ŷ��ͼ�� 

����ʵ�֣� 
����㿪ʼ����������ÿһ��δ���ʹ��ĺ�̣������к�̶�������������ǰ�ڵ㡣 
*/
/*
#include<stdio.h>
#include<string.h>
#define MAXN 10010

int head[MAXN],vis[10*MAXN]; //head[i]��¼��iΪǰ���ĵ�һ����Ĵ��λ�� 

struct node
{ //ǰ�������ݽṹ 
	int to��  //��ǰ�ڵ�ĺ�� 
	int next; //�͵�ǰ�ڵ�ͬǰ������һ�ڵ�Ĵ��λ�� 
} a[MAXN*10];

void DFS(int u)
{
	int i;
	for(i=head[u];i!=-1;i=a[i].next) //���δ���ǰ�ڵ�ĺ�� 
		if(!vis[i])
		{ //��δ���ʹ������־���ʹ������������� 
			vis[i]=1;
			DFS(a[i].to);
		}
	printf("%d\n",u);
}

int main()
{
	int i,j,n,m,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		for(i=0;i<2*m;i++)
		{
			scanf("%d%d",&u,&v);			
			a[i].to=v;            //������ 
			a[i].next=head[u];
			head[u]=i++;
			a[i].to=u;            //������ 
			a[i].next=head[v];
			head[v]=i;
		}
		memset(vis,0,sizeof(vis));
		DFS(1);
	}
	return 0;
} */

#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAXN 10010

struct node
{
	int to;  //��ǰ�ڵ�ĺ�� 
	int vis; //��ǰ�ڵ��Ƿ���ʹ� 
};

vector<node> map[MAXN]; //�ṹ�����͵�vector���� 

void DFS(int u)
{
	int i;
	for(i=0;i<map[u].size();i++) //����ǰ�ڵ�����к�� 
		if(!map[u][i].vis) //�����ǰ�ڵ�δ���ʹ� 
		{
			map[u][i].vis=1; //��־���ʹ� 
			DFS(map[u][i].to); //�������̽ڵ� 
		}
	printf("%d\n",u);
}

int main()
{
	node tmp;
	int i,n,m,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			tmp.to=v;               //������ 
			tmp.vis=0;
			map[u].push_back(tmp);
			tmp.to=u;               //������ 
			tmp.vis=0;
			map[v].push_back(tmp);
		}
		DFS(1);
	}
	return 0;
}
