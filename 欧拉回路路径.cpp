/*
仅经过一次所有的边构成的回路为欧拉回路。
若一个图中所有点的入度的等于出度，则有欧拉回路。

欧拉路径原理： 
一个大的欧拉图删去一个点或一个小的欧拉图仍是一个欧拉图。
一个欧拉图如果从节点s开始深搜则结束点也一定是s。因为如果一个节点
的入度-1，则其出度也一定-1，从s开始搜索只有s的出度-1而入度没变。
在全都搜索完成时，所有点的出入度都为0，所以最后一个点应该为s。
所以从节点s开始搜索，一定会形成一个到s结束的小欧拉图。加上s的前驱节点
就会形成一个更大的欧拉图，直到形成完整的欧拉图。 

具体实现： 
从起点开始，深搜起点的每一个未访问过的后继，等所有后继都处理完后输出当前节点。 
*/
/*
#include<stdio.h>
#include<string.h>
#define MAXN 10010

int head[MAXN],vis[10*MAXN]; //head[i]记录以i为前驱的第一个点的存放位置 

struct node
{ //前向星数据结构 
	int to；  //当前节点的后继 
	int next; //和当前节点同前驱的下一节点的存放位置 
} a[MAXN*10];

void DFS(int u)
{
	int i;
	for(i=head[u];i!=-1;i=a[i].next) //依次处理当前节点的后继 
		if(!vis[i])
		{ //若未访问过，则标志访问过并对其后继深搜 
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
			a[i].to=v;            //正向存边 
			a[i].next=head[u];
			head[u]=i++;
			a[i].to=u;            //反向存边 
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
	int to;  //当前节点的后继 
	int vis; //当前节点是否访问过 
};

vector<node> map[MAXN]; //结构体类型的vector数组 

void DFS(int u)
{
	int i;
	for(i=0;i<map[u].size();i++) //处理当前节点的所有后继 
		if(!map[u][i].vis) //如果当前节点未访问过 
		{
			map[u][i].vis=1; //标志访问过 
			DFS(map[u][i].to); //深搜其后继节点 
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
			tmp.to=v;               //正向存边 
			tmp.vis=0;
			map[u].push_back(tmp);
			tmp.to=u;               //反向存边 
			tmp.vis=0;
			map[v].push_back(tmp);
		}
		DFS(1);
	}
	return 0;
}
