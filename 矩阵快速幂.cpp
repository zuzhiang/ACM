#include<stdio.h>
typedef long long LL;

int n,m;

struct matrix
{
	LL map[100][100];
}a,per;

void init()
{ //������� 
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a.map[i][j]);
			a.map[i][j]%=m;
			per.map[i][j]=(i==j); //���Խ���Ϊ1������Ϊ0��Ϊ��λ���� 
		}
}

matrix multi(matrix a,matrix b)
{ //ʵ��a��b������������ 
	matrix c;
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			c.map[i][j]=0;
			for(k=1;k<=n;k++) c.map[i][j]+=(a.map[i][k]*b.map[k][j])%m;
			c.map[i][j]%=m;
		}
	return c;
}


//ԭ�������������һ����ֻ�ǽ������˷���Ϊ�˾���˷� 
matrix power(int k)
{ //����a�����k���� 
	matrix ans,base;
	ans=per; //��ʼ��Ϊ��λ���� 
	base=a;
	while(k)
	{
		if(k&1) ans=multi(ans,base);
		base=multi(base,base);
		k>>=1;
	}
	return ans;
}

int main()
{
	int i,j,k;
	matrix ans;
	while(~scanf("%d%d%d",&n,&k,&m)) //n*n�ľ���A��k���� % m
	{
		init();
		ans=power(k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%lld ",ans.map[i][j]);
			printf("\n");
		}
	}
	return 0;
}
