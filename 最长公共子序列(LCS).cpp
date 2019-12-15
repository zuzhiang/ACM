/*
状态转移方程
            dp(i-1,j-1)+1,s[i]==t[j]
 dp(i,j)={
            max(dp(i-1,j),dp(i,j-1)),s[i]!=t[j]
*/


/*
公共子序列是最长的，但不一定是上升的
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int i,j,ls,lt,dp[100][100];
	char s[100],t[100];
	memset(dp,0,sizeof(dp));	
	scanf("%s",s+1); //从第二个位置开始存储
	scanf("%s",t+1); //从第二个位置开始存储
	ls=strlen(s+1);
	lt=strlen(t+1);
	for(i=1;i<=ls;i++)
		for(j=1;j<=lt;j++)
		{
			if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	for(i=1;i<=ls;i++)
	{
		for(j=1;j<=lt;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("%d\n",dp[ls][lt]);
	return 0;
}
