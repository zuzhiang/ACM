/*
prime求最小生成树算法
原理:对点进行操作。任选一个点开始，从已加点中选取权值最小的边，
若不构成回路则加入。 
*/
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
#define MAX 1000

int n,m,map[MAX][MAX];

int prime()
{
	int i,j;
	int cur,pos,sum,min;
    int vis[MAX],dis[MAX]; //dis[i]为根节点到i节点的距离 
    cur=1; //任选一节点为根节点 
    sum=0; //总花费 
    memset(vis, 0, sizeof(vis));
    vis[cur] = 1;
    //n为节点的个数 
    for(i=1;i<=n;i++) dis[i]=map[cur][i];
    for(i=0;i<n-1;i++)
	{ //循环n-1次
        min = INF;
        for(j=1;j<=n;j++)
		{ //访问未访问的节点
            if(!vis[j] && dis[j]<min)
			{
                min=dis[j];    //记录最小距离
                pos=j;    	   //记录下标
            }
        }
        vis[pos]=1;      //最小距离点标志访问过
        sum+=min;  	     //总花费距离增加        
        for(j=1;j<=n;j++)
		{
            if(!vis[j] && dis[j]>map[pos][j])
                dis[j]=map[pos][j];
        }    
    } 
    return sum;    	//返回总花费距离
}

int main()
{
	int i,j,t,u,v,w,ans;
	scanf("%d",&t);
	while(t--)
	{		
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++) map[i][j]=INF;				
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]=w;
			map[v][u]=w;
		}
		ans=prime();
		printf("%d\n",ans);
	}
	return 0;
}
