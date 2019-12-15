#include<stdio.h>
typedef long long LL;

int n,m;

struct matrix
{
	LL map[100][100];
}a,per;

void init()
{ //输入矩阵 
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a.map[i][j]);
			a.map[i][j]%=m;
			per.map[i][j]=(i==j); //主对角线为1，其他为0，为单位矩阵 
		}
}

matrix multi(matrix a,matrix b)
{ //实现a、b两个矩阵的相乘 
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


//原理和整数快速幂一样，只是将整数乘法改为了矩阵乘法 
matrix power(int k)
{ //计算a矩阵的k次幂 
	matrix ans,base;
	ans=per; //初始化为单位矩阵 
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
	while(~scanf("%d%d%d",&n,&k,&m)) //n*n的矩阵A的k次幂 % m
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
