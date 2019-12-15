/*

״̬d[i][j]��ʾ��a�����ǰi��Ԫ�أ�b�����ǰj��Ԫ�ز�����b[j]Ϊ��β��LCIS�ĳ��ȡ�
״̬ת�Ʒ���  1. F[i][j] = F[i-1][j] (a[i] != b[j])
              2. F[i][j] = max(F[i-1][k]+1) (1 <= k <= j-1 && b[j] > b[k])

��d[i][j] > 0 �Ļ�����ô������aǰi��Ԫ����һ������a[k]( 1 <= k <= i)����b[j]. ����˵��ǰi��aԪ����û����b[j]��ͬ��Ԫ�ء�

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
	/* �ٶȸ���
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
