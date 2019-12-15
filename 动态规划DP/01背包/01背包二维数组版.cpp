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
	scanf("%d%d",&n,&v); //nΪ��Ʒ������vΪ������� 
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&p[i]); //����ÿ����Ʒ������ͼ�ֵ 
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=v;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++) //DP��� 
		for(j=1;j<=v;j++)
			if(j<w[i]) dp[i][j]=dp[i-1][j]; //����Ų��µ�i����Ʒ 
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]); //�ڷ��벻�ŵ�i����Ʒ��ȡ�ϴ�ֵ 
	printf("%d\n",dp[n][v]); //������Դ����Ʒ������ֵ 
	tol=0;
	for(i=n,j=v;i>0&&j>0;)
	{//Ѱ�Ҵ������Щ��Ʒ 
		if(dp[i][j]==dp[i-1][j-w[i]]+p[i])
		{ //�������˵�i����Ʒ����¼��path������ 
			path[tol]=i;
			tol++;
			j-=w[i]; //����ʣ��ռ�-w[i] 
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
