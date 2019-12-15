/*
定义：
树的重心也叫树的质心。找到一个点,其所有的子树中最大的子树节点数最少,那么这个点就是这棵树的重心,删去重心后，生成的多棵树尽可能平衡。


性质：
1.树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么他们的距离和一样。

2.把两个树通过一条边相连得到一个新的树，那么新的树的重心在连接原来两个树的重心的路径上。

3.把一个树添加或删除一个叶子，那么它的重心最多只移动一条边的距离。

求树的重心，如果有多个重心则输出根节点编号最小的一个
思路：用 DFS寻找以某个节点为根的最大子树的节点最少的一个 
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

int n,nd[20010];
int min_node,min_blc;
vector<int> T[20010];

int max(int a,int b)
{
	return a>b? a:b;
}

void dfs(int node,int pre)
{ //参数：当前节点，当前节点的父亲节点 
	int i,son,max_num;
	nd[node]=1; //以当前节点为根的子树的节点个数 
	max_num=0; //最大子树的节点个数 
	for(i=0;i<T[node].size();i++)
	{ //遍历相邻的每个节点 
		son=T[node][i];
		if(son!=pre)
		{
			dfs(son,node); //递归处理 
			nd[node]+=nd[son]; //回溯时计算子树的节点数 
			max_num=max(max_num,nd[son]);
		}
	}
	max_num=max(max_num,n-nd[node]);
	if(max_num<min_blc)
	{ //找到更小的最大子树的节点数则更新 
		min_blc=max_num;
		min_node=node;
	}
}

int main()
{
	int i,t,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) T[i].clear();
		for(i=0;i<n-1;i++)
		{ //输入并保存树的边 
			scanf("%d%d",&u,&v);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		min_node=0; //最小的根节点 
		min_blc=0x3f3f3f3f; //最大子树节点的最小值 
		dfs(1,0);
		printf("%d %d\n",min_node,min_blc);
	}
	return 0;
}
