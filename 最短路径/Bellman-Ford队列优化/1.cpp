#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	queue<int> Q;
	int i,n,m,u[11],v[11],w[11],dis[11],book[11];
	int inf=0x3f3f3f3f;
	int now;
	scanf("%d %d",&n,&m);
	//初始化dis数组，即源点1到各顶点的距离
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
    //初始化book数组，即当前节点是否处理过
	for(i=1;i<=n;i++)
		book[i]=0;
	//读入两顶点和它们之间的距离
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	//用队列进行优化
	Q.push(1);
	book[1]=1;
	while(!Q.empty())
	{
		now=Q.front();
		Q.pop();
		for(i=1;i<=n;i++)
			if(u[i]==now)
			{
				if(dis[v[i]]>dis[u[i]]+w[i])
				{
					dis[v[i]]=dis[u[i]]+w[i];
					if(book[v[i]]==0)
					{
						Q.push(v[i]);
						book[v[i]]=1;
					}
				}
			}
	}
	//输出
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	printf("\n");
	return 0;
}

/*
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/