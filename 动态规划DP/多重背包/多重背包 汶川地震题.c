/*
现在假设你一共有资金n元，而市场有m种大米，每种大米都是袋装产品，其价格不等，并且只能整袋购买。
请问：你用有限的资金最多能采购多少公斤粮食呢？
Input
输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m(1<=n<=100, 1<=m<=100),分别表示经费的金额和大米的种类，然后是m行数据，每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的价格、每袋的重量以及对应种类大米的袋数。
 

Output
对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例的输出占一行。
 

Sample Input
1
8 2
2 100 4
4 100 2
 

Sample Output
400
*/

#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k,t,n,m,vl[100],wt[100],num[100],dp[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d %d %d",&vl[i],&wt[i],&num[i]);
		memset(dp,0,sizeof(dp));
		for(i=0;i<m;i++)
			for(j=0;j<num[i];j++)
				for(k=n;k>=vl[i];k--)
					if(dp[k]<dp[k-vl[i]]+wt[i])
					dp[k]=dp[k-vl[i]]+wt[i];
		printf("%d\n",dp[n]);  //输出为dp[n]而不是dp[n-1]
	}
	return 0;
}