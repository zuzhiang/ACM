/*
次小生成树，即除最小生成树之外可以生成的权值和最小的树 
原理：利用kruskal算法求出最小生成树，再用不是最小生成树
的权值最小的边替换最小生成树中权值最大的边。 
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
				{ //记录最小生成树中权值最大的边 
					max=a[i].w;
					pos=i;
				}				
			}
			if(cnt>=n-1) break;
		}
		min=0x3f3f3f3f;
		for(i=0;i<m;i++) //从不是最小生成树的边中取最小的 
			if(!vis[i]&&a[i].w<min) min=a[i].w;
		//printf("mst=%d min=%d max=%d\n",mst,min,max);
		printf("次小生成树的值为：%d\n",mst-max+min) ;
	}
	return 0;
}
