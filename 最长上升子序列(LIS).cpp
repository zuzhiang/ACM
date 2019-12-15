#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,len,max,dp[1000];
	char s[1000];
	memset(dp,1,sizeof(dp));
	scanf("%s",s);
	len=strlen(s);
	dp[0]=1;
	for(i=1;i<len;i++)
	{
		max=0;
		for(j=0;j<i;j++)
		{
			if(s[i]>s[j] && dp[j]>max)
				max=dp[j];
		}
		dp[i]=max+1;
	}
	max=0;
	for(i=1;i<len;i++)
		if(dp[i]>max) max=dp[i];
	printf("%d\n",max);
	return 0;	
}
