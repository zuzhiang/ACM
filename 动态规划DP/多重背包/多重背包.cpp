//ת��Ϊ01��������ȫ������⣬�ٶ���죬���Ӷ�O(V*��log n[i])
#include<stdio.h>
#include<string.h>

int n,v,dp[50001]; //��Ʒ�����ͱ������� 

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

//01��������ǰ��Ʒ�۸����� 
void  ZOP(int prz,int wt)
{
	int j;
	for(j=v;j>=wt;j--)
		dp[j]=max(dp[j],dp[j-wt]+prz);
}

//��ȫ��������ǰ��Ʒ�۸����� 
void CP(int prz,int wt) 
{
	int j;
	for(j=wt;j<=v;j++)
		dp[j]=max(dp[j],dp[j-wt]+prz);
}

//���ر�������ǰ��Ʒ�۸����������� 
void MP(int prz,int wt,int cnt) 
{
	//����Ų���ȫ������ת��Ϊ��ȫ������� 
	if(wt*cnt>=v) CP(prz,wt); 
	else //����ת��Ϊ01������� 
	{ //��cnt����ͬ��Ʒ�ֶ��飬ÿ��1��2��4��8����
	  //�����ڱ����������ʣ�µĿ��ܲ���2�Ĵ��� 
		int k=1;
		while(k<cnt)
		{ //k����Ʒ�ļ�ֵ�������ֱ�Ϊ k*prz,k*wt
			ZOP(k*prz,k*wt);
			cnt-=k;
			k<<=1;
		}
		if(cnt>0) ZOP(cnt*prz,cnt*wt);
	}
}

int main()
{
	int i,j,k,w[105],p[105],c[105];
	scanf("%d%d",&n,&v);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&w[i],&p[i],&c[i]);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
		MP(p[i],w[i],c[i]);
	printf("%d\n",dp[v]);
	return 0;
}


