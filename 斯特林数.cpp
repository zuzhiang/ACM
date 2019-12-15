/*
��һ��˹���������������ģ������ֵ�ǰ��� n ��Ԫ�صļ��Ϸ��� k ��Բ���еķ�����Ŀ��

��S(n,k)Ϊ��һ��˹������

�з��ŵĵ�һ��˹�������ݹ鹫ʽΪ��S(n,k)=S(n-1,k-1) + (n-1)*S(n-1,k)

�޷��ŵĵ�һ��˹�������ݹ鹫ʽΪ��S(n,k)=S(n-1,k-1) - (n-1)*S(n-1,k)

�߽�������S(n,0)=0      S(1,1)=1        S(0,0)=1
*/

/*
�ڶ���˹�������ǰѰ��� n ��Ԫ�صļ��ϻ���Ϊ���� k ���ǿ��Ӽ��ķ�������Ŀ��

��S(n,k)Ϊ�ڶ���˹������

���ƹ�ʽ�ǣ���S(n,k) = k*S(n-1,k) + S(n-1,k-1) ,0 < k < n

�߽������� S(n,n) = 1 ,n>=0         S(n,0) = 0 ,n>=1
*/

//ע�⣺��Ԫ�ظ���>20ʱ���ͳ�int�����ˣ�Ҫ�� long long ��

#include<stdio.h>
#include<string.h>
#define MAXN 100

int s1[MAXN][MAXN],s2[MAXN][MAXN],s3[MAXN][MAXN];

void one_one(int n)
{ //�޷��ŵĵ�һ��˹������ 
	int i,j;	
	s1[1][1]=1;
	s1[0][0]=1;
	for(i=1;i<=n;i++) s1[i][0]=0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			s1[i][j]=s1[i-1][j-1]+(i-1)*s1[i-1][j];
}

void one_two(int n)
{ //�з��ŵĵ�һ��˹������ 
	int i,j;	
	s2[1][1]=1;
	s2[0][0]=1;
	for(i=1;i<=n;i++) s2[i][0]=0;
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			s2[i][j]=s2[i-1][j-1]-(i-1)*s2[i-1][j];
}

void two(int n)
{ //�ڶ���˹������ 
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
