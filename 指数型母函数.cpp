//http://www.wutianqi.com/?p=2644
/*
����:HDU 1521  //��n�����ظ�����Ʒ��ȡ��m���������� 
��ͨ��ĸ������Ҫ��������ϵķ���������ָ����ĸ�����������������

ָ����ĸ�������⣺
������8��Ԫ�أ�����a1�ظ�3�Σ�a2�ظ�2�Σ�a3�ظ�3�Ρ�����ȡr����ϣ������������

ָ����ĸ�����ļ�����̾���ģ���������ʽ�˷��Ĺ���
*/
#include<stdio.h>
#include<string.h>
#define MAXN 111
typedef long long LL;

int num[12];
double c1[MAXN],c2[MAXN],factor[12];

void init()
{ //Ԥ����׳� 
	int i;
	factor[0]=1;
	for(i=1;i<12;i++) factor[i]=factor[i-1]*i;
}

void mu(int n,int m)
{ //n����Ʒ���࣬m��ÿ����Ʒ������ 
	int i,j,k;
	memset(c1,0,sizeof(c1)); //c1[i]�洢����ǰi����˵����ս�� 
	memset(c2,0,sizeof(c2)); //c2[i]�洢����ǰi����˵��м��� 
	for(i=0;i<=num[1];i++) //�������һ�����Ż��и����ϵ��
		c1[i]=1/factor[i]; //����ʡ����x��x��Ӧ��ָ������i 
	for(i=2;i<=n;i++)
	{ //����ǰi����˵Ľ�� 
		for(j=0;j<=m;j++)  //���ֻ��ѡm����Ʒ 
			for(k=0;k<=num[i]&&k+j<=m;k++)
				c2[j+k]+=c1[j]/factor[k];
		for(j=0;j<=m;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
}

//����һ��ֵ y*x^i/(n!) ,����n������n��i��n��ֵӦ������ȵģ�y���γ�����n�����еķ�ʽ�� 
int main()
{
	int i,j,m,n,a[11];
	double ans;
	init();
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&num[i]);		
		mu(n,m);
		ans=c1[m]*factor[m];
		printf("%.0lf\n",ans);
	}
	return 0;
}
