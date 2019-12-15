/*
第一类斯特林数是有正负的，其绝对值是包含 n 个元素的集合分作 k 个圆排列的方法数目。

设S(n,k)为第一类斯特林数

有符号的第一类斯特林数递归公式为：S(n,k)=S(n-1,k-1) + (n-1)*S(n-1,k)

无符号的第一类斯特林数递归公式为：S(n,k)=S(n-1,k-1) - (n-1)*S(n-1,k)

边界条件：S(n,0)=0      S(1,1)=1        S(0,0)=1
*/

/*
第二类斯特林数是把包含 n 个元素的集合划分为正好 k 个非空子集的方法的数目。

设S(n,k)为第二类斯特林数

递推公式是：　S(n,k) = k*S(n-1,k) + S(n-1,k-1) ,0 < k < n

边界条件： S(n,n) = 1 ,n>=0         S(n,0) = 0 ,n>=1
*/

//注意：当元素个数>20时，就超int类型了，要用 long long 型

#include<stdio.h>
#include<string.h>
#define MAXN 100

int s1[MAXN][MAXN],s2[MAXN][MAXN],s3[MAXN][MAXN];

void one_one(int n)
{ //无符号的第一类斯特林数 
	int i,j;	
	s1[1][1]=1;
	s1[0][0]=1;
	for(i=1;i<=n;i++) s1[i][0]=0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			s1[i][j]=s1[i-1][j-1]+(i-1)*s1[i-1][j];
}

void one_two(int n)
{ //有符号的第一类斯特林数 
	int i,j;	
	s2[1][1]=1;
	s2[0][0]=1;
	for(i=1;i<=n;i++) s2[i][0]=0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			s2[i][j]=s2[i-1][j-1]-(i-1)*s2[i-1][j];
}

void two(int n)
{ //第二类斯特林数 
	int i,j;	
	s3[0][0]=1;
	s3[1][0]=0;
	s3[1][1]=1;	
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			s3[i][j]=s3[i-1][j-1]+j*s3[i-1][j];
}

int main()
{
	int i,j;
	one_one(MAXN);
	one_two(MAXN);
	two(MAXN);
	for(i=0;i<11;i++)
	{		
		for(j=0;j<=i;j++)
			printf("%d  ",s1[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<11;i++)
	{
		for(j=0;j<=i;j++)
			printf("%d  ",s2[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<11;i++)
	{		
		for(j=0;j<=i;j++)
			printf("%d  ",s3[i][j]);
		printf("\n");
	}
	return 0;
}
