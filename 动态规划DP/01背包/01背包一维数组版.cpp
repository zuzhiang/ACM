#include<stdio.h>
#include<string.h>

int dp[10005];

int main()
{
	int i,j,n,v,w[1005],p[1005];
	while(~scanf("%d%d",&n,&v)) //������Ʒ�������ͱ�������� 
	{
		if(n==0&&v==0) break;
		for(i=0;i<n;i++) //����ÿ����Ʒ������ͼ�ֵ 
			scanf("%d%d",&w[i],&p[i]);
		memset(dp,0,sizeof(dp)); //dp��ʼ��Ϊ0 
		for(i=0;i<n;i++)	
			for(j=v;j>=w[i];j--)//��������������ΪF[i][]ֻ��F[i-1][]�йأ��ҵ�i������Ʒ���벻���F[i-1][]״̬���Ӱ�졣
				if(dp[j]<dp[j-w[i]]+p[i]) dp[j]=dp[j-w[i]]+p[i];
		/*for(i=1;i<=v;i++) //���dp���� 
			printf("%d ",dp[i]);
		printf("\n");*/
		printf("%d\n",dp[v]);
	}
	return 0;
}
