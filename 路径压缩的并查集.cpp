#include<stdio.h>
#include<string.h>

int f[500];

void init(int n) //并查集初始化
{
    int i;
    for(i=1;i<=n;i++) f[i]=i;
}

int find(int x) //在并查集中寻找某个元素的代表元素
{ //路径压缩的并查集 
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int Union(int x,int y) //合并两个元素所在的集合
{
	int fx,fy;
    fx= find(x);
    fy= find(y);
    if(fx==fy) return 0;
    f[fy]=fx;
    return 1;
}

int main()
{
	int i,n,a,b;
	while(~scanf("%d",&n))
	{
		init(n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(i=1;i<=n;i++) printf("%d ",find(i));
		printf("\n");
	}
	return 0;
}
