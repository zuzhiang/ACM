#include<stdio.h>
#include<string.h>
#define MAXN 10010

int p[MAXN],w[MAXN],dp[MAXN];

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int i,j,n,v;
	while(~scanf("%d%d",&n,&v))
	{ //输入物品数量和背包容量 
		//输入每种物品的价值和重量 
		for(i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);		
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			for(j=w[i];j<=v;j++) //从w[i]开始
				dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
		printf("%d\n",dp[v]);
	}
	return 0;
}
