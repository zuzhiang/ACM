#include<stdio.h>
#include<string.h>

int dp[10005];

int main()
{
	int i,j,n,v,w[1005],p[1005];
	while(~scanf("%d%d",&n,&v)) //输入物品的数量和背包的体积 
	{
		if(n==0&&v==0) break;
		for(i=0;i<n;i++) //输入每件物品的体积和价值 
			scanf("%d%d",&w[i],&p[i]);
		memset(dp,0,sizeof(dp)); //dp初始化为0 
		for(i=0;i<n;i++)	
			for(j=v;j>=w[i];j--)//背包中逆序是因为F[i][]只和F[i-1][]有关，且第i件的物品加入不会对F[i-1][]状态造成影响。
				if(dp[j]<dp[j-w[i]]+p[i]) dp[j]=dp[j-w[i]]+p[i];
		/*for(i=1;i<=v;i++) //输出dp数组 
			printf("%d ",dp[i]);
		printf("\n");*/
		printf("%d\n",dp[v]);
	}
	return 0;
}
