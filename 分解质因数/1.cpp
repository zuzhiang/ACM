#include<stdio.h>
#include<string.h>
#define MAX 10000

int main()
{
	int i,j,n,t,a[MAX];
	printf("请输入一个合数:\n");
	while(~scanf("%d",&n))
	{
		if(n<2) 
		{
			printf("%d\n",n);
			continue;
		}
		else 
		{
			i=2;
			t=n;
			memset(a,0,sizeof(a));
			while(n>1)
			{
				if(n%i==0)
				{
					a[i]++;					
					n=n/i;
				}
				else i++;				
			}
			for(i=2;i<=t;i++)
			{
				if(a[i]!=0)
				{
					printf("%d^%d",i,a[i]);
					break;
				}
			}
			for(j=i+1;j<=t;j++)
			{
				if(a[j]!=0)
					printf("*%d^%d",j,a[j]);
			}
			printf("\n");
		}
		printf("请输入一个合数:\n");
	}
	return 0;
}
