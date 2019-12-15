/*

状态d[i][j]表示以a数组的前i个元素，b数组的前j个元素并且以b[j]为结尾的LCIS的长度。
状态转移方程  1. F[i][j] = F[i-1][j] (a[i] != b[j])
              2. F[i][j] = max(F[i-1][k]+1) (1 <= k <= j-1 && b[j] > b[k])

若d[i][j] > 0 的话，那么在数组a前i个元素中一定存在a[k]( 1 <= k <= i)等于b[j]. 否则说明前i个a元素中没有与b[j]相同的元素。

*/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int i,j,k,ls,lt,ans,mmax,dp[100][100];
	char s[1000],t[1000];
	scanf("%s",s+1);
	scanf("%s",t+1);
	ls=strlen(s+1);
	lt=strlen(t+1);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=ls;i++)
		for(j=1;j<=lt;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(s[i]==t[j])
			{
				mmax=0;
				for(k=1;k<j;k++)
					if(t[j]>t[k]) mmax=max(mmax,dp[i-1][k]);
				dp[i][j]=mmax+1;
			}
		}
	/* 速度更快
	for(int i = 1; i <= LS; i++)
    {
        mmax = 0;
        for(int j = 1; j <= lt; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(t[i] > t[j] && mmax < dp[i-1][j]) mmax = dp[i-1][j];
            else if(t[i] == t[j])
                dp[i][j] = mmax + 1;
        }
    }	
	*/
	ans=0;
	for(i=1;i<=lt;i++)
		ans=max(ans,dp[ls][i]);
	for(i=1;i<=ls;i++)
	{
		for(j=1;j<=lt;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("%d\n",ans);
	return 0;
}

/*

142638591
276351

*/
