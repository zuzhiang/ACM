/*
一个数n的大于sqrt(n)的质因子只可能有一个， 
所以，先去计算因子为2~sqrt(n)的个数，若最后每次整除后n的值不为1，
则当前n的值就是其大于sqrt(n)的因子，它的幂次为1 、 
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 1000010

int tol,pri[MAX],p[MAX];

void is_prime()
{
	int i,j;
	tol=0;
	memset(pri,1,sizeof(pri));
	for(i=2;i<MAX;i++)	
		if(pri[i])
		{
			p[tol++]=i;
			for(j=2*i;j<MAX;j+=i) pri[j]=0;		
		}	
}

int main()
{
	int i,n;
	is_prime();
	while(~scanf("%d",&n))
	{
		for(i=0;i<tol;i++)
		{
			if(n%p[i]==0) printf("%d ",p[i]);
			while(n%p[i]==0) n/=p[i];
			//如果当前数是质数或者找到了所有质因子则退出 
			if(pri[n]||n==1) break;							
		}
		if(n>1) printf("%d",n);
		printf("\n");
	}
	return 0;
}
