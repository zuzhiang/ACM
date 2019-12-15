/*
Kruskal求最小生成树算法
原理：对边进行操作。从所有未处理的边中选权值最小的，
若不会使节点形成回路则加入，直到加入n-1条边结束。 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAXN 5000
using namespace std; 

int q,total=0,f[MAXN]; //n为节点个数，total为边的条数，f为并查集的数组

struct node //包含起始节点/终止节点和权值的结构体
{
    int u,v,w; //u为起始节点，v为终止节点，w是权值
} a[MAXN];

int cmp(node x,node y) //将结构体数组按权值递增排序
{
    return x.w<y.w;
}

void init(int n) //并查集初始化
{
    int i;
    for(i=1;i<=n;i++) f[i]=i;
}

int find(int x) //在并查集中寻找某个元素的代表元素
{
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int Union(int x,int y) //合并两个元素所在的集合
{
	int fx,fy;
    fx= find(x);
    fy= find(y);
    if(fx==fy) return 0;
    f[fx]=fy;
    return 1;
}

int main()
{
	int i,t,n,m,cnt,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n);
		for(i=0;i<m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a,a+total,cmp);   //将结构体数组按权值升序排列
		cnt=0;
		ans=0;		
		for(i=0;i<m;i++)
		{
		    if(Union(a[i].u,a[i].v))
		    {
		    	ans+=a[i].w;
		    	cnt++;
			}
			if(cnt>=n-1) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
