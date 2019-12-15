/*
Floyd-Warshall算法，又称Floyd算法
为多源最短路算法，不可处理负权 
原理：用i经过点k到j的距离更新i直接到j的距离
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,u,m,n,v,w,map[101][101]; //map[i][j]保存顶点i和顶点j之间的距离
	int inf=0x3f3f3f3f;
	scanf("%d %d",&n,&m); //顶点个数和边数
	//初始化
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			map[i][j]=inf;
	for(i=1;i<=n;i++)
		map[i][i]=0;
	//读入边
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		map[u][v]=w;
	}
	//算法核心语句
	for(k=1;k<=n;k++)         //用顶点k更新顶点i和顶点j之间的距离
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	//输出结果
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	return 0;
}

/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
