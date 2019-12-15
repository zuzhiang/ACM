/*
组合数的递推公式：c(n,m)=c(n-1,m-1)+c(n-1,m)
*/

#include<stdio.h>
typedef long long LL;

int A(int n,int m)
{
	int i,ans;
	ans=1;
	for(i=n;i>=m;i--) ans*=i;
	return ans;
}

LL c[1010][1010];

void C()
{ //求组合数 
	int i,j;	
	for(i=0;i<1005;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
		
}

int main()
{
	int i,j,n,m,ans;
	C();
	for(i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
			printf("%lld ",c[i][j]);
		printf("\n");
	}		
	printf("请输入排列中的n和m:\n");
	scanf("%d %d",&n,&m);
	ans=A(n,m);	
	return 0;
}
