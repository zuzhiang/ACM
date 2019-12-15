#include<stdio.h>
#include<string.h>
#define MAX 100000

int pri[MAX],p[MAX];
int tol;

void init()
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
	int i;
	init();
	printf("%d\n",p[tol-1]);
	for(i=0;i<20;i++) printf("%d ",p[i]);
	return 0;
}
