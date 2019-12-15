#include<stdio.h>

int dp[105][10005];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int i,j,n,v,tol,w[105],p[105],path[105];
	scanf("%d%d",&n,&v); //n为物品数量，v为背包体积 
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&p[i]); //输入每个物品的体积和价值 
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=v;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++) //DP求解 
		for(j=1;j<=v;j++)
			if(j<w[i]) dp[i][j]=dp[i-1][j]; //如果放不下第i个物品 
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]); //在放与不放第i个物品中取较大值 
	printf("%d\n",dp[n][v]); //输出可以存放物品的最大价值 
	tol=0;
	for(i=n,j=v;i>0&&j>0;)
	{//寻找存放了哪些物品 
		if(dp[i][j]==dp[i-1][j-w[i]]+p[i])
		{ //如果存放了第i个物品，记录在path数组中 
			path[tol]=i;
			tol++;
			j-=w[i]; //背包剩余空间-w[i] 
		}
		i--;
	}
	for(i=tol-1;i>=0;i--)
		printf("%d ",path[i]);
	printf("\n");
	return 0;
}

/*
5 10
2 6 2 3 6 5 5 4 4 6
*/
