/*
按字典序从小到大输出所有拓扑排序序列
 
思路：先对所有元素从小到大排序，然后利用递归从结果的第1位开始
循环寻找入度为0的节点，使其入度-1，结果当前位设为当前值，并将
与其相连的节点的入度-1，然后递归向下一个位置搜索。当前路径搜索
完毕后，取消当前节点的影响。
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100

int n,m,ans[MAXN]; //n为节点个数，m为边数，ans存储结果 
int a[MAXN],dgr[MAXN],map[MAXN][MAXN]; //a存储节点，dgr存储入度，map[i][j]表示有从i到j的边 

void solve(int depth)
{
	int i,j;
	if(depth==n)
	{ //如果深度为n则已经处理完，直接输出结果 
		for(i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(i=0;i<n;i++) //按字典序处理入度为0的节点 
		if(dgr[a[i]]==0) 
		{ //如果当前节点入度为0 
			dgr[a[i]]--; //入度-1，后面不在处理 
			ans[depth]=a[i]; //结果当前位设为a[i] 
			for(j=0;j<n;j++) //将当前节点的后继入度-1 
				if(map[a[i]][a[j]]) dgr[a[j]]--;
			solve(depth+1); //递归处理下一个位置 
			dgr[a[i]]++; //取消当前节点的影响 
			for(j=0;j<n;j++)
				if(map[a[i]][a[j]]) dgr[a[j]]++;
		}
}

int main()
{
	int i,j,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n); //按从小到大排序 
		memset(map,0,sizeof(map));
		memset(dgr,0,sizeof(dgr));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
			dgr[v]++;
		}
		solve(0);
	}
	return 0;
}

/*
8 9
1 5 8 4 6 2 7 3
1 2
1 3
1 4
2 5
3 6
4 7
5 8
6 8
7 8

4 2
1 2 6 7
1 2
2 6

5 4
1 2 3 4 5
1 4
3 1
5 1
2 1
*/
