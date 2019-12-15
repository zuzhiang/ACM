//http://www.renfei.org/blog/bipartite-matching.html
#include<stdio.h>
#include<string.h>

int vis[666]; //节点是否访问过
int link[666]; //与该节点相连接节点的编号
int map[666][666];//值为1表示u，v节点有边
int gn,gm; //二分图两部分的节点数，两部分的节点编号都是从1开始

int find(int u)
{ //匈牙利算法
	int i;
	for(i=1;i<=gm;i++)
	{
		if(map[u][i] && vis[i]==0) //如果节点i与v相连并且未被查找过 
		{
			vis[i]=1;	//标记i为已查找过  
			if(link[i]==-1 || find(link[i])) //如果i未在前一个匹配M中，或者i在匹配M中，但是从与i相邻的节点出发可以有增广路径  
			{
				link[i]=u; //记录查找成功记录，更新匹配M（即“取反”）
				return 1;  //返回查找成功
			}
		}
	}
	return 0;
}

int main()
{
	int i,n,u,v,num;
	scanf("%d %d",&gn,&gm);
	memset(map,0,sizeof(map));
	for(i=1;i<=gm;i++)
		link[i]=-1;
	scanf("%d",&n);//边数
	while(n--)
	{
		scanf("%d %d",&u,&v);//相连节点的编号
		map[u][v]=1;
	}
	num=0;
	for(i=1;i<=gn;i++)
	{
		memset(vis,0,sizeof(vis));
		if(find(i)) num++;
	}
	printf("num=%d\n",num);
	return 0;
}

/*

4 4 7
1 1
1 3
2 1
3 1
3 2
4 3
4 4


3 3 4
1 1
1 3
2 2
3 2

*/
