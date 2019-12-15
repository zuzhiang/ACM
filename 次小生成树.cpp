/*
��С��������������С������֮��������ɵ�Ȩֵ����С���� 
ԭ������kruskal�㷨�����С�����������ò�����С������
��Ȩֵ��С�ı��滻��С��������Ȩֵ���ıߡ� 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define MAX 10010
using namespace std;

int f[MAX];

struct node
{
	int u,v,w;	
} a[MAX];

int cmp(node x,node y)
{
	return x.w<y.w;
}

void init(int n)
{
	int i;
	for(i=0;i<=n;i++) f[i]=i;
}

int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

int Union(int x,int y)
{
	int fx,fy;
	fx=find(x);
	fy=find(y);
	if(fx==fy) return 0;
	f[fx]=fy;
	return 1;
}

int main()
{
	int i,j,t,n,m;
	int cnt,pos,mst,min,max;
	int vis[MAX];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a,a+m,cmp);
		cnt=0;
		mst=0;
		max=0;
		pos=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<m;i++)
		{
			if(Union(a[i].u,a[i].v))
			{
				mst+=a[i].w;
				cnt++;
				vis[i]=1;
				if(a[i].w>max) 
				{ //��¼��С��������Ȩֵ���ı� 
					max=a[i].w;
					pos=i;
				}				
			}
			if(cnt>=n-1) break;
		}
		min=0x3f3f3f3f;
		for(i=0;i<m;i++) //�Ӳ�����С�������ı���ȡ��С�� 
			if(!vis[i]&&a[i].w<min) min=a[i].w;
		//printf("mst=%d min=%d max=%d\n",mst,min,max);
		printf("��С��������ֵΪ��%d\n",mst-max+min) ;
	}
	return 0;
}
